/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:32 PM IST
 * Problem: bigrams
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef MONU_LOCAL_JUDGE
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

// given a number n and n numbers in the next line
// 1 1 2 2
// abccdd
// ab bc cc cd dd
class Solution {
public:
  void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    while (n--) {
      std::cin >> a[n];
    }

    int count = 0;

    for (int i = 0; i < a.size(); i++) {
      if (a[i] > 1) {
        if (a[i] > 2) {
          std::cout << "YES" << std::endl;
          return;
        }
        count++;
      }
    }

    if (count > 1) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
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
