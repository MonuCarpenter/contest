/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:09 PM IST
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
  i64 n;
  std::cin >> n;

  std::vector<i64> a(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  i64 start = 0;

  while (start + 1 < n) {
    if (a[start] > a[start + 1]) {
      a[start + 1] += a[start];
    }
    start++;
  }

  std::cout << a[n - 1] << "\n";
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
