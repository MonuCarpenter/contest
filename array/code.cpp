/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 04:40 PM IST
 * Problem: array
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
    i64 n;
    std::cin >> n;

    if (n == 1) {
      std::cout << "1\n";
      return;
    }

    if (n == 2) {
      std::cout << "-1\n";
      return;
    }

    std::cout << 1 << " " << 2 << " " << 3 << " ";
    i64 current_sum = 6;
    for (i64 i = 3; i < n; i++) {
      std::cout << current_sum << " ";
      current_sum *= 2;
    }
    std::cout << std::endl;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 t;
  std::cin >> t;

  Solution sol;
  while (t--) {
    sol.solve();
  }

  return 0;
}
