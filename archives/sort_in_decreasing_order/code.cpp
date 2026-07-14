/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 09:57 PM IST
 * Problem: sort_in_decreasing_order
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
private:
  static bool compare(const int a, const int b) { return a > b; }

public:
  void sort_decreasing_1(std::vector<int> &vi) {
    std::sort(vi.begin(), vi.end(), compare);
  }
  void sort_decreating_2(std::vector<int> &vi) {
    std::sort(vi.begin(), vi.end(),
              [](const int a, const int b) { return a > b; });
  };
  void sort_decreasing_3(std::vector<int> &vi) {
    std::sort(vi.rbegin(), vi.rend());
  }
  void solve() {
    std::vector<int> vi = {5, 2, 9, 1, 5, 6};
    sort_decreasing_1(vi);
    log("Sorted in decreasing order (method 1):", vi);

    std::vector<int> vi2 = {5, 2, 9, 1, 5, 6};
    sort_decreating_2(vi2);
    log("Sorted in decreasing order (method 2):", vi2);

    std::vector<int> vi3 = {5, 2, 9, 1, 5, 6};
    sort_decreasing_3(vi3);
    log("Sorted in decreasing order (method 3):", vi3);
  }
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
