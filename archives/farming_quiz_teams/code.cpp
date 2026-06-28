/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 08:06 PM IST
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
private:
  float calculated_min_distance(int n) {
    float cal_distance = 0;

    return 0.00;
  };

public:
  void solve() {
    int n;

    int test_case_index = 1;

    while (std::cin >> n) {
      float result = calculated_min_distance(n);
      std::cout << "Case " << test_case_index++ << ": " << std::fixed
                << std::setprecision(2) << result << "\n";
    }
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;
  sol.solve();

  return 0;
}
