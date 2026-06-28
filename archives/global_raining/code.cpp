/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 05:29 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifndef ONLINE_JUDGE
#include "../cpp-dump/cpp-dump.hpp"
#define log(...) cpp_dump(__VA_ARGS__)
template <> inline void cpp_dump::write_log(std::string_view output) {
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
  int filledWater(const std::string &str) {
    int result = 0;

    std::stack<int> s;

    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '\\') { // NOTE: its '\' only but  we need to write like
                            // '\\'
        s.push(i);
      } else if (str[i] == '/' && !s.empty()) {
        result += i - s.top();
        s.pop();
      }
    }

    return result;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  int test_cases;
  std::cin >> test_cases;

  while (test_cases--) {
    std::string str;
    std::cin >> str;

    std::cout << sol.filledWater(str) << '\n';
  }

  return 0;
}
