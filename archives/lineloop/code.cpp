/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:28 AM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
//
// #ifndef ONLINE_JUDGE
// #include "../cpp-dump/cpp-dump.hpp"
// #define log(...) cpp_dump(__VA_ARGS__)
// template <> inline void cpp_dump::write_log(std::string_view output) {
//   std::cout << output << '\n';
// }
// #else
// #define log(...)
// #define CPP_DUMP_SET_OPTION(...)
// #define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
// #define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
// #define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
// #define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
// #endif

class Solution {
public:
  void line_loop() {
    // 2
    // 0
    //  --> 1, 2
    //  4
    //  1 2 0
    //  --> 1 4 2 3
    int N;
    std::cin >> N;

    int arr[N];

    int secure_n = N;
    arr[0] = 1;

    int i = 2;
    while (N--) {
      int x;
      std::cin >> x;

      arr[x + 1] = N == 1 ? i-- : i;
      i++;
    }

    // print the arr
    for (int i = 0; i < secure_n; i++) {
      std::cout << arr[i] << ' ';
    }
  };
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution solution;
  solution.line_loop();

  return 0;
}
