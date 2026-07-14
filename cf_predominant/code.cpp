/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 07:00 PM IST
 * Problem: cf_predominant
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
public:
  void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    // preL[i] = #1 - #2 - #3 in prefix [0, i]
    // preM[i] = #1 + #2 - #3 in prefix [0, i]
    std::vector<int> preL(n), preM(n);
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) c1++;
      else if (a[i] == 2) c2++;
      else c3++;
      preL[i] = c1 - c2 - c3;
      preM[i] = c1 + c2 - c3;
    }

    // right_max[i] = max(preM[i], ..., preM[n-2]) (excludes last index for R)
    std::vector<int> right_max(n, -1e9);
    if (n >= 2) {
      right_max[n - 2] = preM[n - 2];
      for (int i = n - 3; i >= 0; i--) {
        right_max[i] = std::max(preM[i], right_max[i + 1]);
      }
    }

    // Try each possible left-part end (leave >=2 elements for M and R)
    for (int i = 0; i <= n - 3; i++) {
      if (preL[i] >= 0 && right_max[i + 1] >= preM[i]) {
        std::cout << "YES\n";
        return;
      }
    }
    std::cout << "NO\n";
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
