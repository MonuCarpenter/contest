/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:41 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

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

/**
5 8
1 2 3 2 0 3 4 5
3 3
1 0 2
4 3
4 4 1
0

---------------------case 1
5 and 8;
4 3 2 3 5 2 1 0

first step
-> 3 2 1 2 4 1 0
-> 2 1 0 1 3 0 0
-> 1 0 0 1 3 0 0
-> 0 0 0 1 3 0 0
-> 0 0 0 0 2 0 0
two more steps to make all zeroes
**/

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int H, W;

  while (std::cin >> H) {
    if (H == 0) {
      break;
    }

    std::cin >> W;
    std::vector<int> wts(W);

    for (int i = 0; i < W; i++) {
      int w;
      std::cin >> w;
      wts[i] = H - w;
    };

    int cycles = 0;

    int start = 0;
    while (start < W) {
      if (wts[start] == 0) {
        start++;
        continue;
      }

      int end = start + 1;
      while (end < W && wts[end]) {
        end++;
      }

      for (int i = start; i < end; i++) {
        wts[i]--;
      }
      cycles++;

      if (wts[start] == 0)
        start++;
    }
    std::cout << cycles << '\n';
  }
  return 0;
}
