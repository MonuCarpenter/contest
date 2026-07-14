/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 04:17 PM IST
 * Problem: epig_dance_off
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
  int count_dancers(int n, int m) {
    std::vector<std::string> s(n + 1);

    for (int i = 0; i < n; ++i) {
      std::cin >> s[i];
    }

    log(s);
    int result = 0;
    for (int i = 0; i < m; i++) {
      bool flag = false;
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '_') {
          flag = true;
        }
      }
      if (flag) {
        result++;
      }
    }

    return result + 1;
  }
  void solve() {
    int n, m;
    std::cin >> n >> m;

    std::cout << count_dancers(n, m) << std::endl;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;
  sol.solve();

  return 0;
}
