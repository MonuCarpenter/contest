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

    // Create only code.cpp, input.txt, output.txt if they do not exist
    std::vector<std::string> files = {"code.cpp", "input.txt", "output.txt"};
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
            << " * Time: ";
        // Get current Indian time (IST) in 12-hour format with am/pm
        std::time_t t = std::time(nullptr);
        std::tm* ist_tm = std::gmtime(&t);
        ist_tm->tm_hour += 5;
        ist_tm->tm_min += 30;
        mktime(ist_tm);
        int hour12 = ist_tm->tm_hour;
        std::string ampm = "AM";
        if (hour12 >= 12) {
            ampm = "PM";
            if (hour12 > 12) hour12 -= 12;
        }
        if (hour12 == 0) hour12 = 12;
        char timebuf[64];
        std::strftime(timebuf, sizeof(timebuf), "%Y-%m-%d", ist_tm);
        out << timebuf << " ";
        out << std::setw(2) << std::setfill('0') << hour12 << ":"
            << std::setw(2) << std::setfill('0') << ist_tm->tm_min << ":"
            << std::setw(2) << std::setfill('0') << ist_tm->tm_sec << " " << ampm << " IST\n";
        out << " * Problem: " << folder.string() << "\n"
            << "*/\n\n"
            << "#include <bits/stdc++.h>\n"
            << "\n"
            << "using i64 = long long;\n"
            << "using u64 = unsigned long long;\n"
            << "using u32 = unsigned;\n"
            << "\n"
            << "#ifndef ONLINE_JUDGE\n"
            << "#include \"./cpp-dump/cpp-dump.hpp\"\n"
            << "#define log(...) cpp_dump(__VA_ARGS__)\n"
            << "template <>\n"
            << "inline void cpp_dump::write_log(std::string_view output) {\n"
            << "    std::cout << output << '\\n';\n"
            << "}\n"
            << "#else\n"
            << "#define log(...)\n"
            << "#define CPP_DUMP_SET_OPTION(...)\n"
            << "#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)\n"
            << "#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)\n"
            << "#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)\n"
            << "#define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)\n"
            << "#endif\n"
            << "\n"
            << "int solve() {\n"
            << "    return 0;\n"
            << "}\n"
            << "\n"
            << "int main() {\n"
            << "    CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);\n"
            << "    std::ios::sync_with_stdio(false);\n"
            << "    std::cin.tie(nullptr);\n"
            << "\n"
            << "    int t;\n"
            << "    std::cin >> t;\n"
            << "\n"
            << "    while (t--) {\n"
            << "        solve();\n"
            << "    }\n"
            << "\n"
            << "    return 0;\n"
            << "}\n";
        out.close();
    }
}

void display_loader(std::atomic<bool>& loading) {
    std::vector<std::string> spin = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    size_t frame = 0;
    int seconds = 0;

    while (loading) {
        std::cout << "\b" << spin[frame];
        frame = (frame + 1) % spin.size();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        seconds++;
    }
    std::cout << "\bDone! (" << seconds / 10 << "s)" << std::endl;
}

void run_tests(const fs::path& folder) {
    // Only use input.txt and output.txt for single test case
    fs::path input_path = folder / "input.txt";
    fs::path output_path = folder / "output.txt";
    std::string input_str, result, expected, diff_str;
    std::string test_case_number = "1";

    // Compile the C++ program first
    // To simulate online judge, add -DONLINE_JUDGE to the compile command
    bool use_online_judge = std::getenv("OJ") != nullptr; // Set OJ=1 in env to enable
    std::string compile_command = "g++-15 -std=c++20 ";
    if (use_online_judge) compile_command += "-DONLINE_JUDGE ";
    compile_command += "-o " + folder.string() + "/code " + folder.string() + "/code.cpp";
    
    std::cout << "\033[1mCompiling...\033[0m\n";
    int compile_status = std::system(compile_command.c_str());

    if (compile_status != 0) {
        std::cerr << "\033[1;31mCompilation failed for folder " << folder << ". Exiting.\033[0m\n";
        return;
    }

    // Print full input, output, expected in bold before the table
    std::ifstream input_file(input_path);
    std::stringstream input_buffer;
    input_buffer << input_file.rdbuf();
    input_str = input_buffer.str();
    std::cout << "\033[1mInput:\033[0m\n" << input_str << "\n";

    std::string run_command = folder.string() + "/code < " + input_path.string();
    std::array<char, 128> buffer;
    FILE* pipe = popen(run_command.c_str(), "r");
    if (pipe) {
        while (fgets(buffer.data(), 128, pipe) != nullptr) {
            result += buffer.data();
        }
        pclose(pipe);
    }
    std::cout << "\033[1mOutput:\033[0m\n" << result << "\n";

    std::ifstream expected_file_full(output_path);
    std::stringstream expected_buffer_full;
    expected_buffer_full << expected_file_full.rdbuf();
    expected = expected_buffer_full.str();
    std::cout << "\033[1mExpected:\033[0m\n" << expected << "\n";
    std::cout << "\033[1m(Use OJ=1 ./run folder to simulate online judge)\033[0m\n\n";

    // Print summary table header
    std::cout << "\033[1m================================================================================================================\033[0m\n";
    std::cout << "\033[1m| Test Case | Status   | Input                | Output               | Expected             | Diff                |\033[0m\n";
    std::cout << "\033[1m|-----------|----------|----------------------|----------------------|----------------------|---------------------|\033[0m\n";
    if (is_effectively_empty(input_path)) {
        input_str = "No Input";
        result = "No Output";
        expected = fs::exists(output_path) ? "See file" : "No expected output file";
        diff_str = "No difference to show";
        std::string status_colored = "\033[1;43;30m Skipped \033[0m"; // Yellow background, black text
        auto compact = [](const std::string& s) {
            std::string out;
            std::istringstream iss(s);
            std::string line;
            bool first = true;
            while (std::getline(iss, line)) {
                if (!first) out += "  ";
                out += line;
                first = false;
            }
            if (out.empty()) out = "(empty)";
            if (out.size() > 20) out = out.substr(0, 17) + "...";
            return out;
        };
        std::cout << "| " << std::setw(9) << test_case_number << " | " << std::setw(9) << status_colored << " | "
                  << std::setw(20) << compact(input_str) << " | "
                  << std::setw(20) << compact(result) << " | "
                  << std::setw(20) << compact(expected) << " | "
                  << std::setw(19) << compact(diff_str) << " |\n";
    } else {
        // We already have input_str, result, and expected from the debug section above
        // No need to re-read input or re-run the program
        
        // Fix output comparison: ignore trailing whitespace and newlines
        auto trim = [](std::string s) {
            // Remove trailing whitespace
            while (!s.empty() && (s.back() == '\n' || s.back() == '\r' || s.back() == ' ' || s.back() == '\t')) s.pop_back();
            // Remove leading whitespace
            while (!s.empty() && (s.front() == '\n' || s.front() == '\r' || s.front() == ' ' || s.front() == '\t')) s.erase(0, 1);
            return s;
        };
        std::string status, status_colored;
        std::string trimmed_result = trim(result);
        std::string trimmed_expected = trim(expected);
        if (trimmed_result == trimmed_expected) {
            status = "Passed";
            status_colored = "\033[1;42;30m Passed \033[0m"; // Green background, black text
        } else {
            status = "Failed";
            status_colored = "\033[1;41;97m Failed \033[0m"; // Red background, white text
        }
        
        auto compact = [](const std::string& s) {
            std::string out;
            std::istringstream iss(s);
            std::string line;
            bool first = true;
                while (std::getline(iss, line)) {
                    if (!first) out += "  ";
                    out += line;
                    first = false;
                }
                if (out.empty()) out = "(empty)";
                if (out.size() > 20) out = out.substr(0, 17) + "...";
                return out;
            };
            std::cout << "| " << std::setw(9) << test_case_number << " | " << std::setw(9) << status_colored << " | "
                      << std::setw(20) << compact(input_str) << " | "
                      << std::setw(20) << compact(result) << " | "
                      << std::setw(20) << "N/A" << " | "
                      << std::setw(19) << "N/A" << " |\n";
        } else {
            while (fgets(buffer.data(), 128, pipe) != nullptr) {
                result += buffer.data();
            }
            pclose(pipe);

            // Read expected output
            std::ifstream expected_file(output_path);
            std::stringstream expected_buffer;
            expected_buffer << expected_file.rdbuf();
            expected = expected_buffer.str();

            // Fix output comparison: ignore trailing whitespace and newlines
            auto trim = [](std::string s) {
                // Remove trailing whitespace
                while (!s.empty() && (s.back() == '\n' || s.back() == '\r' || s.back() == ' ' || s.back() == '\t')) s.pop_back();
                // Remove leading whitespace
                while (!s.empty() && (s.front() == '\n' || s.front() == '\r' || s.front() == ' ' || s.front() == '\t')) s.erase(0, 1);
                return s;
            };
            std::string status, status_colored;
            std::string trimmed_result = trim(result);
            std::string trimmed_expected = trim(expected);
            if (trimmed_result == trimmed_expected) {
                status = "Passed";
                status_colored = "\033[1;42;30m Passed \033[0m"; // Green background, black text
            } else {
                status = "Failed";
                status_colored = "\033[1;41;97m Failed \033[0m"; // Red background, white text
                // Debug: show the actual strings being compared
                std::cout << "\033[1;33mDEBUG - Result length: " << trimmed_result.length() 
                         << ", Expected length: " << trimmed_expected.length() << "\033[0m\n";
                std::cout << "\033[1;33mDEBUG - Result bytes:\033[0m ";
                for (char c : trimmed_result) std::cout << (int)c << " ";
                std::cout << "\n\033[1;33mDEBUG - Expected bytes:\033[0m ";
                for (char c : trimmed_expected) std::cout << (int)c << " ";
                std::cout << "\n";
            }

            // Compare expected and actual output line by line
            std::istringstream expected_stream(expected);
            std::istringstream result_stream(result);
            std::string expected_line, result_line;
            bool difference_found = false;
            std::stringstream diff_buffer;
            while (std::getline(expected_stream, expected_line) && std::getline(result_stream, result_line)) {
                if (expected_line != result_line) {
                    diff_buffer << "- " << expected_line << " | + " << result_line << "\n";
                    difference_found = true;
                }
            }
            while (std::getline(expected_stream, expected_line)) {
                diff_buffer << "- " << expected_line << "\n";
                difference_found = true;
            }
            while (std::getline(result_stream, result_line)) {
                diff_buffer << "+ " << result_line << "\n";
                difference_found = true;
            }
            diff_str = difference_found ? diff_buffer.str() : "No difference";

            // Print horizontal table row
            auto compact = [](const std::string& s) {
                std::string out;
                std::istringstream iss(s);
                std::string line;
                bool first = true;
                while (std::getline(iss, line)) {
                    if (!first) out += "  ";
                    out += line;
                    first = false;
                }
                if (out.empty()) out = "(empty)";
                if (out.size() > 20) out = out.substr(0, 17) + "...";
                return out;
            };
            std::cout << "| " << std::setw(9) << test_case_number << " | " << std::setw(9) << status_colored << " | "
                      << std::setw(20) << compact(input_str) << " | "
                      << std::setw(20) << compact(result) << " | "
                      << std::setw(20) << compact(expected) << " | "
                      << std::setw(19) << compact(diff_str) << " |\n";
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