/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:52 AM IST
 * Problem: sleeping_in_hotels
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifndef MONU_LOCAL_JUDGE
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
  int find_max_distance(std::string s) {
    int n = s.size();
    int max_dist = 0;

    std::vector<int> x_pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'X') {
        x_pos.push_back(i);
      }
    }

    if (x_pos.empty()) return 0;

    int first_x = x_pos.front();
    int last_x = x_pos.back();

    max_dist = std::max(max_dist, first_x - 1);
    max_dist = std::max(max_dist, n - last_x - 2);

    for (size_t i = 1; i < x_pos.size(); i++) {
      int gap = x_pos[i] - x_pos[i - 1] - 1;
      max_dist = std::max(max_dist, (gap - 1) / 2);
    }

    return max_dist;
  }
  void solve() {
    std::string s;
    while (std::cin >> s) {
      int result = find_max_distance(s);
      std::cout << result << std::endl;
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
