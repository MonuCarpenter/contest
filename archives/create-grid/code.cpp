/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:54 PM IST
 * Problem: create-grid
 */

#include <bits/stdc++.h>
#include <vector>

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
  std::vector<std::string> createGrid(int m, int n) {
    std::vector<std::string> matrix;

    for (int i = 0; i < m; i++) {
      if (i == 0) {
        matrix.push_back(std::string(n, '.'));
      } else {
        std::string s = std::string(n, '#');
        s[s.size() - 1] = '.';
        matrix.push_back(s);
      }
    }
    return matrix;
  }
  void solve() {
    int m = 2, n = 3;

    std::vector<std::string> result = createGrid(m, n);
    log(result);
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
