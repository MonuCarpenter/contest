/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:21 PM IST
 * Problem: D
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
    int length;
    std::cin >> length;
    std::vector<long long> vault(length);
    for (int idx = 0; idx < length; ++idx) std::cin >> vault[idx];

    int zeroSeen = 0;
    for (int idx = 0; idx < length; ++idx) {
      if (vault[idx] == 0) ++zeroSeen;
    }

    if (zeroSeen == 1) {
      std::cout << "NO\n";
      return;
    }

    std::cout << "YES\n";
    std::string tribe(length, 'A');
    if (zeroSeen == 0) {
      for (int idx = 0; idx < length; ++idx) tribe[idx] = 'A';
      std::cout << tribe << '\n';
      return;
    }
    bool firstHanded = false;
    bool secondHanded = false;
    for (int idx = 0; idx < length; ++idx) {
      if (vault[idx] == 0) {
        if (!firstHanded) {
          tribe[idx] = 'A';
          firstHanded = true;
        } else if (!secondHanded) {
          tribe[idx] = 'B';
          secondHanded = true;
        } else {
          tribe[idx] = 'A';
        }
      } else {
        tribe[idx] = 'C';
      }
    }
    std::cout << tribe << '\n';
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
