#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>
#include <atomic>
#include <vector>

namespace fs = std::filesystem;

std::string get_ist_time() {
    auto now = std::time(nullptr);
    auto utc = *std::gmtime(&now);
    auto ist_hours = utc.tm_hour + 5;
    auto ist_minutes = utc.tm_min + 30;
    if (ist_minutes >= 60) {
        ist_minutes -= 60;
        ist_hours += 1;
    }
    if (ist_hours >= 24) {
        ist_hours -= 24;
    }
    
    // Convert to 12-hour format
    std::string ampm = (ist_hours >= 12) ? "PM" : "AM";
    int display_hour = ist_hours;
    if (display_hour == 0) display_hour = 12;
    else if (display_hour > 12) display_hour -= 12;
    
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << display_hour 
        << ":" << std::setw(2) << ist_minutes << " " << ampm << " IST";
    return oss.str();
}

bool is_effectively_empty(const fs::path& file_path) {
    if (!fs::exists(file_path)) return true;
    std::ifstream file(file_path);
    std::string line;
    while (std::getline(file, line)) {
        for (char c : line) {
            if (!std::isspace(c)) return false;
        }
    }
    return true;
}

void create_default_files(const fs::path& folder) {
    fs::create_directories(folder);
    
    fs::path code_file = folder / "code.cpp";
    fs::path input_file = folder / "input.txt";
    fs::path output_file = folder / "output.txt";
    
    if (!fs::exists(code_file)) {
        std::ofstream out(code_file);
        out << "// Created at " << get_ist_time() << "\n\n"
            << "#include <bits/stdc++.h>\n"
            << "using namespace std;\n"
            << "\n"
            << "#ifndef ONLINE_JUDGE\n"
            << "#include \"../cpp-dump/dump.hpp\"\n"
            << "#else\n"
            << "#define dump(...)\n"
            << "#endif\n"
            << "\n"
            << "void solve() {\n"
            << "    // Your code here\n"
            << "}\n"
            << "\n"
            << "int main() {\n"
            << "    ios_base::sync_with_stdio(false);\n"
            << "    cin.tie(NULL);\n"
            << "\n"
            << "    int t;\n"
            << "    cin >> t;\n"
            << "\n"
            << "    while (t--) {\n"
            << "        solve();\n"
            << "    }\n"
            << "\n"
            << "    return 0;\n"
            << "}\n";
        out.close();
    }
    
    // Create input.txt if it doesn't exist
    if (!fs::exists(input_file)) {
        std::ofstream out(input_file);
        out << "1\n"; // Default: 1 test case
        out.close();
    }
    
    // Create output.txt if it doesn't exist
    if (!fs::exists(output_file)) {
        std::ofstream out(output_file);
        out << "\n"; // Empty expected output initially
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

    // Read input
    std::ifstream input_file(input_path);
    std::stringstream input_buffer;
    input_buffer << input_file.rdbuf();
    input_str = input_buffer.str();

    // Run the program ONCE
    std::string run_command = folder.string() + "/code < " + input_path.string();
    std::array<char, 128> buffer;
    FILE* pipe = popen(run_command.c_str(), "r");
    if (pipe) {
        while (fgets(buffer.data(), 128, pipe) != nullptr) {
            result += buffer.data();
        }
        pclose(pipe);
    }

    // Read expected output
    std::ifstream expected_file(output_path);
    std::stringstream expected_buffer;
    expected_buffer << expected_file.rdbuf();
    expected = expected_buffer.str();

    // Print full input, output, expected in bold before the table
    std::cout << "\033[1mInput:\033[0m\n" << input_str << "\n";
    std::cout << "\033[1mOutput:\033[0m\n" << result << "\n";
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
                if (!first) out += "  ";
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
                if (!first) out += "  ";
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
    
    // Print table footer
    std::cout << "\033[1m================================================================================================================\033[0m\n";
    
    // Clean up - remove compiled program
    fs::remove(folder / "code");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <folder_name>\n";
        return 1;
    }

    fs::path folder(argv[1]);
    create_default_files(folder);
    
    // Check if any input.txt file is present
    if (fs::exists(folder / "input.txt")) {
        std::cout << "\033[1;32mRunning tests for " << folder << "\033[0m\n";
        run_tests(folder);
    } else {
        std::cout << "\033[1;33mNo input files found in " << folder << ". Only creating default files.\033[0m\n";
    }

    return 0;
}
