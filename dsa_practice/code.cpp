/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 12:08 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifndef ONLINE_JUDGE
#include "../cpp-dump/cpp-dump.hpp"
#define log(...) cpp_dump(__VA_ARGS__)
template <>
inline void cpp_dump::write_log(std::string_view output) {
    std::cout << output << '\n';
}
#else
#define log(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
#endif

class Solution {
    public: 
        void basicInputOutput() {
            int n; 
            std::cin >> n; 
            std::vector<int> arr(n); 
            for(int i = 0; i < n; i++) {
                std::cin >> arr[i]; 
            }
            for(int i = 0; i < n; i++) {
                std::cout << arr[i] << ' '; 
            }
        }
        int intCountDigitsInNumber(int n) {
            int count = 0; 
            while(n) {
                n = n/10; 
                count++;
            }

            return count; 
        }
        int reverseNumber(int n) {
            int result = 0; 

            while(n) {
                int lastDigit = n % 10; 
                 result = result * 10 + lastDigit; 
                 n /= 10; 
            }
            return result; 
        }

        bool palindromeNumber(int n) {
            int reverse = reverseNumber(n); 
            if(n == reverse) return true; 
            return false; 
        }

        int gcdOfNumbers(int a, int b) {
            int low = std::min(a, b); 
            
            for(int i = low; i >= 1; i--) {
                if(b % i == 0 && a % i == 0) {
                    return i; 
                }
            }
            return -1; 
        }
        void swap(int arr[], int a, int b) {
            int temp = arr[a]; 
            arr[a] = arr[b]; 
            arr[b] = temp; 
        }
        void selectionSort(int N, int arr[]) {
            for(int i = 0; i < N; i++) {
                int minElement = arr[i]; 
                int minIndex = i; 

                for(int j = i + 1; j < N; j++) {
                    if(minElement > arr[j]) {
                        minElement = arr[j]; 
                        minIndex = j; 
                    }
                }
                swap(arr, i, minIndex);
            }
        }
        void bubbleSort(int N, int arr[]) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N - i - 1; j++) {
                    if(arr[j] > arr[j + 1]) {
                        swap(arr, j, j + 1); 
                    }
                }
            }
        }
        bool isPalindromeString(string s) {
            int start = 0, end = s.length(); 
            while(start < end) {
                if(s[start] != s[end]) return false; 
                start++; 
                end--;
            }
            return true; 
        }
        string longestPalindrome(string s) {
            return ""; 
        }
};

int main() {
    CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution sol;
   // sol.basicInputOutput();
   // int n = 56465;
   // int result = sol.intCountDigitsInNumber(n);
   // int result = sol.reverseNumber(n); 
   //  bool result = sol.palindromeNumber(n);
    // int result = sol.gcdOfNumbers(9, 12); 
    // std::cout << "result:: " << result << std::endl; 
    // int arr[5] = { 5, 2, 8, 1, 3 };
    // sol.bubbleSort(5, arr);

    // std::cout << "result -->";
    // for(int i = 0; i < 5; i++) {
    //     std::cout << arr[i] << ' ';
    // }
    // std::cout << '\n';
    bool result = sol.isPalindromeString("aba");
    std::cout << "result: " << result << std::endl; 

    return 0;
}
