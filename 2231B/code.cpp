/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 08:23 PM IST
 * Problem: Another sorting problem
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
    i64 N;
    std::cin >> N;

    std::vector<i64> a(N);

    int diff = 0;
    int diff2 = 0;

    for (int i = 0; i < N; i++) {
      std::cin >> a[i];
    }

    log("scanned a", a);

    for (int i = 0; i < N - 2 && a[i] > a[i + 1]; i++) {
      diff = a[i] - a[i + 1];
      diff2 = a[i + 2] - a[i + 1];
    }

    log("diff ---->", diff, diff2);
    std::string result = "NO";

    if (diff2 >= diff) {
      std::vector<i64> b = a;

      log("shallowed b", b);

      for (int i = 0; i < N - 1; i++) {
        if (b[i + 1] < b[i]) {
          b[i + 1] += diff2;
        } else {
          b[i] += diff2;
        }
      }

      log("added diff2 b", b);
      if (is_sorted(b.begin(), b.end())) {
        result = "YES";
      }
    } else {
      std::vector<i64> b = a;

      for (int i = 0; i < N - 1; i++) {
        if (b[i + 1] < b[i]) {
          b[i + 1] += diff;
        } else {
          b[i] += diff;
        }
      }

      log("added diff b", b);
      if (is_sorted(b.begin(), b.end())) {
        result = "YES";
      }
    }

    log(" ------->< result ><------------", result);
    std::cout << result << '\n';
    return;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  int t;
  std::cin >> t;

  while (t--) {
    sol.solve();
  }

  return 0;
}
