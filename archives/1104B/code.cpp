/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 08:05 PM IST
 * Problem: Annoying the ghost
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
  void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }

    int result = 0;

    /// we will try for bubble sort and for each swap we will increase the
    /// result
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        if (a[j] > a[j + 1]) {
          std::swap(a[j], a[j + 1]);
          std::swap(b[j], b[j + 1]);
          result += b[j] + b[j + 1];
        }
      }
    }

    // now we willl check for mismatch with arr-b for each mismatch we will
    // increase the result by 1
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        result++;
      }
    }

    std::cout << result << '\n';
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  Solution solution;

  while (t--) {
    solution.solve();
  }

  return 0;
}
