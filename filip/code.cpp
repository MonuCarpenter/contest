/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:14 AM IST
 * Problem: Filip
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

class Solution {
public:
  int reverse(int n) {
    int rev = 0;
    while (n > 0) {
      rev = rev * 10 + n % 10;
      n /= 10;
    }
    return rev;
  };
  void filip() {
    int x, y;
    std::cin >> x >> y;
    std::cout << std::max(reverse(x), reverse(y)) << '\n';
  }
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution solution;

  solution.filip();
  return 0;
}
