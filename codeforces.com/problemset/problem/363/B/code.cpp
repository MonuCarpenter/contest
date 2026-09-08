/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 09:12 AM IST
 * Problem: B
 */

#include <iostream>
#include <vector>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef MONU_LOCAL_JUDGE
#include "../../../../../cpp-dump/cpp-dump.hpp"
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
    int k;
    std::cin >> k;

    std::vector<int> dp(n);

    for (int i = 0; i < n; i++)
      std::cin >> dp[i];

    int curr = 0;
    for (int i = 0; i < k; i++) {
      curr += dp[i];
    }

    int start = 0;
    int best = curr;
    int id = 0;
    while (start + k < n) {
      curr = curr - dp[start] + dp[start + k];
      if (best > curr) {
        best = curr;
        id = start + 1;
      }
      start++;
    }

    std::cout << (id + 1) << std::endl;
  };
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;
  sol.solve();

  return 0;
}
