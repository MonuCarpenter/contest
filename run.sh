#!/bin/bash


# Function to check if a file is effectively empty (including whitespace)
is_effectively_empty() {
    local file=$1
    # Check if the file is empty or contains only whitespace
    if [ ! -s "$file" ] || [ -z "$(tr -d '[:space:]' < "$file")" ]; then
        return 0  # True, file is empty or whitespace only
    else
        return 1  # False, file has non-whitespace content
    fi
}
# Function to display loader animation
display_loader() {
    local pid=$1
    local i=0
    local spin=("⠋" "⠙" "⠹" "⠸" "⠼" "⠴" "⠦" "⠧" "⠇" "⠏")
    local frame=0
    echo -ne "Running tests... "
    while kill -0 $pid 2> /dev/null; do
        printf "\b${spin[$frame]}"
        frame=$(( (frame + 1) % 10 ))
        sleep 0.1
        ((i++))
    done
    printf "\bDone! (%ds)\n" "$i"
}

# Function to create default folder structure and files
create_default_files() {
    local folder=$1

    # Create folder if it doesn't exist
    [ ! -d "$folder" ] && mkdir -p "$folder" && echo "Folder $folder created."

    # Create default files if they do not exist
    for file in code.cpp input1.txt output1.txt input2.txt output2.txt; do
        [ ! -f "$folder/$file" ] && echo -e "" > "$folder/$file" && echo "Default $file created in $folder."
    done

    # Create default C++ file if it does not exist
   if is_effectively_empty "$folder/code.cpp"; then
        cat > "$folder/code.cpp" << EOF
/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: $(date +"%Y-%m-%d %H:%M:%S")
 * Problem: $folder
**/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int T;
    std::cin >> T;

    while (T--)
        solve();

    return 0;
}
EOF
        echo "Default code.cpp created in $folder."
    fi
}



# Function to compile and run the C++ program
run_tests() {
    local folder=$1

    # Compile C++ program
    g++-14 -std=c++20 -o "$folder/code" "$folder/code.cpp"
    if [ $? -ne 0 ]; then
        echo "Compilation failed for folder $folder. Exiting."
        exit 1
    fi

    # Loop through all input files
    for input_file in "$folder"/input*.txt; do
        test_case_number=$(basename "$input_file" | sed 's/input\([0-9]*\)\.txt/\1/')
        output_file="$folder/output${test_case_number}.txt"

        # Check if input file is effectively empty
        if is_effectively_empty "$input_file"; then
            echo -e "\nTest case #${test_case_number}:"
            echo -e "\033[34mStatus: \033[1;34mSkipped\033[0m"
            echo -e "\033[33mInput:\033[0m"
            echo -e "No Input"
            echo -e "\033[33mOutput:\033[0m"
            echo -e "No expected output file"
            echo -e "\033[33mExpected Output:\033[0m"
            [ -f "$output_file" ] && cat "$output_file" || echo -e "No expected output file"
            echo -e "\033[33mDifference:\033[0m"
            echo -e "No difference to show"
            echo
            continue
        fi
        
        # Run the test case
        output=$("$folder/code" < "$input_file" 2>/dev/null)
        if [ $? -ne 0 ]; then
            echo "Error running test case $test_case_number"
            continue
        fi

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
    folder=$(pwd)
else
    folder=$1
fi

# Create default files in the specified folder if they don't exist
create_default_files "$folder"

# Run tests based on folder path in the background
run_tests "$folder" &
test_pid=$!

# Display the loader while the tests are running
display_loader $test_pid

# Wait for the tests to complete
wait $test_pid
