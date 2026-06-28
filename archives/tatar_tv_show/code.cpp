/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 04:19 PM IST
 * Problem: Tatar: Tv show
 */

#include <bits/stdc++.h>
#include <iostream>

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
  int n;
  std::cin >> n;
  int k;
  std::cin >> k;

  std::string s;
  std::cin >> s;

  for (int i = 0; i < n - k; i++) {
    if (s[i] == '0')
      continue;
    else {
      s[i] = s[i] == '0' ? '1' : '0';
      s[i + k] = s[i + k] == '0' ? '1' : '0';
    }
  }

  std::string result = "YES";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      result = "NO";
      break;
    }
  }

  std::cout << result << std::endl;
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
