/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 08:26 AM IST
 * Problem: sort
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

typedef std::tuple<int, std::string, std::string> tiss;  

class Solution {
private:
  static bool comp(const int a, const int b) { return a > b; }

public:
  void sort_tuple(std::vector<tiss> &tp) {
    std::sort(tp.begin(), tp.end(), [](const tiss &a, const tiss &b) {
      return std::tie(std::get<0>(a), std::get<2>(a), std::get<1>(b)) <
             std::tie(std::get<0>(b), std::get<2>(b), std::get<1>(a));
    });
  }
  void sort_decreasing(std::vector<int> &vi) {
    // first way
    std::sort(vi.rbegin(), vi.rend());

    // second way
    std::sort(vi.begin(), vi.end(),
              [](const int a, const int b) { return a > b; });

    // same way as second
    std::sort(vi.begin(), vi.end(), comp);
  }
  void solve() {}
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  Solution sol;
  while (t--) {
    sol.solve();
  }

  return 0;
}
