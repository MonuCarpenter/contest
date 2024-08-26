#!/bin/bash

# Function to display loader animation
display_loader() {
    local pid=$1
    local delay=0.1
    spin='-\|/'

    echo -ne "Running tests..."
    while kill -0 $pid 2> /dev/null; do
        local temp=${spin#?}
        printf "[%c]" "$spin"
        local spin=$temp${spin%"$temp"}
        sleep $delay
        printf "\b\b\b"
    done
    echo -ne "      \b\b\b\b\b\b"
    echo -ne "\n"
}

# Function to create default folder structure and files
create_default_files() {
    local folder=$1

    # Create folder if it doesn't exist
    if [ ! -d "$folder" ]; then
        mkdir -p "$folder"
        echo "Folder $folder created."
    fi

    # Check if code.cpp exists, if not create default template
    if [ ! -f "$folder/code.cpp" ]; then
        cat > "$folder/code.cpp" <<EOF
/*
 * Author: Monu Carpenter
 * Time: $(date +"%Y-%m-%d %H:%M:%S")
 * Handle: m_o_n_u
**/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();

    std::cout.flush();
    return 0;
}

EOF
        echo "Default code.cpp created in $folder."
    fi

    # Check if input1.txt exists, if not create default template
    if [ ! -f "$folder/input1.txt" ]; then
        echo -e "" > "$folder/input1.txt"
        echo "Default input1.txt created in $folder."
    fi

    # Check if output1.txt exists, if not create default template
    if [ ! -f "$folder/output1.txt" ]; then
        echo -e "" > "$folder/output1.txt"
        echo "Default output1.txt created in $folder."
    fi

    # Check if input2.txt exists, if not create default template
    if [ ! -f "$folder/input2.txt" ]; then
        echo -e "" > "$folder/input2.txt"
        echo "Default input2.txt created in $folder."
    fi

    # Check if output2.txt exists, if not create default template
    if [ ! -f "$folder/output2.txt" ]; then
        echo -e "" > "$folder/output2.txt"
        echo "Default output2.txt created in $folder."
    fi
}

# Function to compile and run the C++ program
run_tests() {
    local folder=$1

    # Compile C++ program
    g++ -o "$folder/code" "$folder/code.cpp"

    # Check if compilation was successful
    if [ $? -ne 0 ]; then
        echo "Compilation failed for folder $folder. Exiting."
        exit 1
    fi

    # Loop through all input files
    for input_file in "$folder"/input*.txt; do
        test_case_number=$(basename "$input_file" | sed 's/input\([0-9]*\)\.txt/\1/')
        output_file="$folder/output${test_case_number}.txt"

        # Check if input file is empty
        if [ ! -s "$input_file" ]; then
            echo -e "\nTest case #${test_case_number}:"
            echo -e "\033[34mStatus: \033[1;34mSkipped (Input file is empty)\033[0m"
            echo -e "\033[33mInput:\033[0m"
            echo -e "Empty input file"
            echo -e "\033[33mOutput:\033[0m"
            echo -e "No output"
            echo -e "\033[33mExpected Output:\033[0m"
            if [ -f "$output_file" ]; then
                cat "$output_file"
            else
                echo -e "No expected output file"
            fi
            echo -e "\033[33mDifference:\033[0m"
            echo -e "No difference to show"
            echo
            continue
        fi

        # Run the test case
        output=$("$folder/code" < "$input_file" 2>/dev/null)
        expected=$(cat "$output_file")

        # Compare output and expected output
        if [ "$output" = "$expected" ]; then
            status="\033[32mPassed\033[0m"
        else
            status="\033[31mFailed\033[0m"
        fi

        # Log results directly to console
        echo -e "\nTest case #${test_case_number}:"
        echo -e "\033[33mStatus: $status\033[0m"
        echo -e "\033[33mInput:\033[0m"
        cat "$input_file"
        echo -e "\033[33mOutput:\033[0m"
        echo "$output"
        echo -e "\033[33mExpected Output:\033[0m"
        echo "$expected"
        echo -e "\033[33mDifference:\033[0m"
        diff -u <(echo "$expected") <(echo "$output")
        echo
    done

    # Clean up - remove compiled program
    rm "$folder/code"
}

# Check if argument (folder path) is provided
if [ $# -eq 0 ]; then
    echo "No folder path provided. Running in current directory..."

    # Set folder path to current directory
    folder=$(pwd)

    # Check if default files exist, create if necessary
    create_default_files "$folder"
else
    folder=$1

    # Create default files in the specified folder if they don't exist
    create_default_files "$folder"
fi

# Run tests based on folder path in the background
run_tests "$folder" &
test_pid=$!

# Display the loader while the tests are running
display_loader $test_pid

# Wait for the tests to complete
wait $test_pid
