/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 12:06 AM IST
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

class Solution {
public:
  std::string add_digits(std::string str) { return std::to_string(str.size()); }

  int count_digits(std::string str) {
    int op_count = 1;
    while (str != "1") {
      str = add_digits(str);
      op_count++;
    }
    return op_count;
  }
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution solution;

  std::string str;

  while (std::cin >> str) {
    if (str == "END") {
      break;
    }

    std::cout << solution.count_digits(str) << '\n';
  }
  return 0;
}
