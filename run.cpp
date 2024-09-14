#include <sys/wait.h>

#include <chrono>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

bool is_effectively_empty(const fs::path& file) {
    // Check if file is empty or contains only whitespace
    std::ifstream infile(file);
    std::stringstream buffer;
    buffer << infile.rdbuf();
    return buffer.str().find_first_not_of(" \t\n\r") == std::string::npos;
}

void create_default_files(const fs::path& folder) {
    // Create folder if it doesn't exist
    if (!fs::exists(folder)) {
        fs::create_directories(folder);
        std::cout << "Folder " << folder << " created." << std::endl;
    }

    // Create default files if they do not exist
    std::vector<std::string> files = {"code.cpp", "input1.txt", "output1.txt", "input2.txt", "output2.txt"};
    for (const auto& file : files) {
        fs::path file_path = folder / file;
        if (!fs::exists(file_path)) {
            std::ofstream out(file_path);
            out.close();
        }
    }

    // Create default C++ file if it does not exist or is empty
    fs::path cpp_file = folder / "code.cpp";
    if (is_effectively_empty(cpp_file)) {
        std::ofstream out(cpp_file);
        out << "/*\n"
            << " * Author: Monu Carpenter\n"
            << " * Handle: m_o_n_u\n"
            << " * Time: " << __DATE__ << " " << __TIME__ << "\n"
            << " * Problem: " << folder.string() << "\n"
            << "*/\n\n"
            << "#include <bits/stdc++.h>\n"
            << "#define _for(n) for (int i = 0; i < n; i++)\n"
            << "typedef long long ll;\n\n"
            << "void solve() {}\n\n"
            << "int main() {\n"
            << "    std::ios::sync_with_stdio(false);\n"
            << "    std::cin.tie(nullptr);\n"
            << "    int T;\n"
            << "    std::cin >> T;\n"
            << "    while (T--)\n"
            << "        solve();\n"
            << "    return 0;\n"
            << "}\n";
        out.close();
    }
}

void display_loader(std::atomic<bool>& loading) {
    std::vector<std::string> spin = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    size_t frame = 0;
    int seconds = 0;

    std::cout << "Running...  ";
    while (loading) {
        std::cout << "\b" << spin[frame];
        frame = (frame + 1) % spin.size();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        seconds++;
    }
    std::cout << "\bDone! (" << seconds / 10 << "s)" << std::endl;
}

void run_tests(const fs::path& folder) {
    // Compile the C++ program
    std::string compile_command = "g++-14 -std=c++20 -o " + folder.string() + "/code " + folder.string() + "/code.cpp";
    int compile_status = std::system(compile_command.c_str());

    if (compile_status != 0) {
        std::cerr << "Compilation failed for folder " << folder << ". Exiting." << std::endl;
        return;
    }

    // Loop through all input files
    for (const auto& entry : fs::directory_iterator(folder)) {
        if (entry.path().filename().string().find("input") != std::string::npos) {
            std::string test_case_number = entry.path().filename().string().substr(5, 1);  // e.g., "input1.txt"
            fs::path output_file = folder / ("output" + test_case_number + ".txt");

            // Check if input file is effectively empty
            if (is_effectively_empty(entry.path())) {
                std::cout << "\nTest case #" << test_case_number << ":\n";
                std::cout << "\033[34mStatus: \033[1;34mSkipped\033[0m\n";
                std::cout << "\033[33mInput:\033[0m\nNo Input\n";
                std::cout << "\033[33mOutput:\033[0m\nNo expected output file\n";
                std::cout << "\033[33mExpected Output:\033[0m\n";
                if (fs::exists(output_file)) {
                    std::ifstream exp_out(output_file);
                    std::cout << exp_out.rdbuf();
                } else {
                    std::cout << "No expected output file\n";
                }
                std::cout << "\033[33mDifference:\033[0m\nNo difference to show\n";
                continue;
            }

            // Run the test case
            std::string run_command = folder.string() + "/code < " + entry.path().string();
            std::array<char, 128> buffer;
            std::string result;
            FILE* pipe = popen(run_command.c_str(), "r");
            if (!pipe) {
                std::cerr << "Error running test case " << test_case_number << std::endl;
                continue;
            }
            while (fgets(buffer.data(), 128, pipe) != nullptr) {
                result += buffer.data();
            }
            pclose(pipe);

            // Compare with expected output
            std::ifstream expected_file(output_file);
            std::stringstream expected_buffer;
            expected_file >> expected_buffer.rdbuf();
            std::string expected = expected_buffer.str();

            std::string status = (result == expected) ? "\033[32mPassed\033[0m" : "\033[31mFailed\033[0m";

            // Log results directly to console
            std::cout << "\nTest case #" << test_case_number << ":\n";
            std::cout << "\033[33mStatus: " << status << "\033[0m\n";
            std::cout << "\033[33mInput:\033[0m\n";
            std::ifstream input_file(entry.path());
            std::cout << input_file.rdbuf();
            std::cout << "\n";
            std::cout << "\033[33mOutput:\033[0m\n"
                      << result << std::endl;

            std::cout << "\033[33mExpected Output:\033[0m\n"
                      << expected << std::endl;

            // Compare expected and actual output line by line
            std::istringstream expected_stream(expected);
            std::istringstream result_stream(result);
            std::string expected_line, result_line;

            bool difference_found = false;
            while (std::getline(expected_stream, expected_line) && std::getline(result_stream, result_line)) {
                if (expected_line != result_line) {
                    std::cout << "- Expected: " << expected_line << "\n";
                    std::cout << "+ Found: " << result_line << "\n";
                    difference_found = true;
                }
            }

            if (!difference_found && expected_stream.eof() && result_stream.eof()) {
                std::cout << "No difference found\n";
            } else {
                // Handle any leftover lines if one file is longer than the other
                while (std::getline(expected_stream, expected_line)) {
                    std::cout << "- Expected: " << expected_line << "\n";
                    difference_found = true;
                }
                while (std::getline(result_stream, result_line)) {
                    std::cout << "+ Found: " << result_line << "\n";
                    difference_found = true;
                }
            }
        }
    }

    // Clean up - remove compiled program
    fs::remove(folder / "code");
}

int main(int argc, char* argv[]) {
    std::string folder;

    if (argc > 1) {
        folder = argv[1];
    } else {
        std::cout << "No folder path provided. Running in current directory..." << std::endl;
        folder = fs::current_path();
    }

    create_default_files(folder);

    std::atomic<bool> loading(true);
    std::thread loader_thread(display_loader, std::ref(loading));

    // Run tests based on folder path
    run_tests(folder);

    loading = false;
    loader_thread.join();

    return 0;
}