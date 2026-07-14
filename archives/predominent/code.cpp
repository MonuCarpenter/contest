/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:19 AM IST
 * Problem: predominent
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

    std::vector<int> in(n);

    for (int i = 0; i < n; ++i) {
      std::cin >> in[i];
    }

    /*
     *  a) count[1] >= count[2] + count[3]
     *  b) count[1] + count[2] >= count[3]
     *  c) non empty
     */
    int satisfied_conditions = 0;
    std::vector<int> counts(4, 0);

    for (int i = 0; i < n; i++) {
      if (satisfied_conditions == 0) {
        if (counts[1] >= counts[2] + counts[3]) {
          satisfied_conditions++;
          // make all counts to zero
          counts[1] = counts[2] = counts[3] = 0;
        }
      } else if (satisfied_conditions == 1) {
        if (counts[1] + counts[2] >= counts[3]) {
          satisfied_conditions++;
          counts[1] = counts[2] = counts[3] = 0;
        }
      } else if (satisfied_conditions == 2) {
        if (counts[1] + counts[2] + counts[3] > 0) {
          satisfied_conditions++;
          counts[1] = counts[2] = counts[3] = 0;
        }
      }
      counts[in[i]]++;
    }

    if (satisfied_conditions == 3) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
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
