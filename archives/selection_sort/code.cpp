/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:30 PM IST
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
    void swap(int arr[], int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    void selectionSort(int arr[], int N) {
        for (int i = 0; i < N - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                swap(arr, i, min_index);
            }
        }
    }
    void bubbleSort(int arr[], int N) {
        for(int i=0; i<N; i++) {
          for(int j=0; j<N-i-1; j++) {
            if(arr[j] > arr[j+1])
              swap(arr, j, j+1); 
          }
        }
    }
    
};

int main() {
    CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution sol;

    int inputArray[] = {34, 56, 23, 66};
    int N = sizeof(inputArray) / sizeof(inputArray[0]);
    sol.bubbleSort(inputArray, N);

    std::cout << "result:";
    for (int i = 0; i < N; i++) {
        std::cout << ' ' << inputArray[i];
    }
    std::cout << '\n';
    return 0;
}
