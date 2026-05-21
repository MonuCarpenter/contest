/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 12:18 PM IST
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

int solve() {
  i64 n, ind_cost, group_cost;
  std::cin >> n >> ind_cost >> group_cost;

  i64 per_three_cost = std::min(ind_cost * 3, group_cost);
  i64 per_two_cost = std::min(ind_cost * 2, group_cost);
  i64 per_one_cost = std::min(ind_cost, group_cost);

  i64 trees = n / 3;
  i64 twos = ((n % 3) / 2);
  i64 ones = ((n % 3) % 2);

  std::cout << (trees * per_three_cost) + (twos * per_two_cost) +
                   (ones * per_one_cost)
            << '\n';
  return 0;
}

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
