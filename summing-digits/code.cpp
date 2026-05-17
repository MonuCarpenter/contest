/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:49 PM IST
 * Problem: Su, */

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
  int sum_digits(int n) {
    int result = 0;
    while (n > 0) {
      result += n % 10;
      n /= 10;
    }
    return result;
  };

  int sum(int n) {
    if (n < 10)
      return n;

    int result = sum_digits(n);
    if (result < 10)
      return result;

    return sum(result);
  };
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  int n;
  while (std::cin >> n) {
    if (n == 0)
      break;

    std::cout << sol.sum(n) << std::endl;
  }
  return 0;
}
