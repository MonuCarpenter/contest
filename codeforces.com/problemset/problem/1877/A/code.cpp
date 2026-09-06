/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:03 PM IST
 * Problem: A
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

class Solution {
  // key notes:
  // n -> teams
  // each pair matchup once
  // two int as result
  // eff = total goal - total goals by opp
  // give effs of n-1
  // find eff of nth
public:
  void solve() {
    int n;
    std::cin >> n;
    n--;

    i64 sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      sum += x;
    }

    std::cout << -sum << "\n";
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
