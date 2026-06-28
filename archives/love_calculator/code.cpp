/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:16 AM IST
 * Problem: Love Calculator.
 * Verdict: AC
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
  bool is_single_digit(float x) { return x < 10; };
  float calculate(std::string s1, std::string s2) {
    float s1_score = 0, s2_score = 0;

    for (char c : s1) {
      s1_score += (c - 'A' + 1);
    }

    for (char c : s2) {
      s2_score += (c - 'A' + 1);
    }

    while (!is_single_digit(s1_score)) {
      float temp = 0;

      for (char c : std::to_string((int)s1_score)) {
        temp += (c - '0');
      }

      s1_score = temp;
    }

    while (!is_single_digit(s2_score)) {
      float temp = 0;

      for (char c : std::to_string((int)s2_score)) {
        temp += (c - '0');
      }

      s2_score = temp;
    }
    // percentage of the ration of these two scores
    return std::min(s1_score, s2_score) / std::max(s1_score, s2_score) * 100;
  };
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  std::string s1, s2;

  while (std::cin >> s1 >> s2) {
    std::cout << sol.calculate(s1, s2) << " %\n";
  }
  return 0;
}
