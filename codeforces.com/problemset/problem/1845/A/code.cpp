/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:25 AM IST
 * Problem: 1845A Forbidden Integer
 * Translated from Python:
 *   if x != 1: YES n*1
 *   elif k==1 or (k==2 and n%2==1): NO
 *   else: YES n//2, [3 if odd else 2] + [2]*(n//2-1)
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
    int n, k, x;
    std::cin >> n >> k >> x;

    if (x != 1) {
      std::cout << "YES\n";
      std::cout << n << "\n";
      for (int i = 0; i < n; i++) {
        std::cout << 1 << (i + 1 == n ? '\n' : ' ');
      }
      return;
    }
    if (k == 1 || (k == 2 && n % 2 == 1)) {
      std::cout << "NO\n";
      return;
    }

    std::cout << "YES\n";
    std::cout << n / 2 << "\n";
    std::vector<int> ans;

    ans.reserve(n / 2);
    ans.push_back(n % 2 == 1 ? 3 : 2);

    for (int i = 0; i < n / 2 - 1; i++)
      ans.push_back(2);

    for (int i = 0; i < (int)ans.size(); i++) {
      std::cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
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
