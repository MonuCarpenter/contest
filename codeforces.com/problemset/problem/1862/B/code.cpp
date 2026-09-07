/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 05:11 PM IST
 * Problem: B
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
    std::vector<i64> a(n);

    for (i64 i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int len = 1;
    std::vector<int> result;

    result.push_back(a[0]);

    for (int i = 1; i < n; i++) {
      if (a[i - 1] <= a[i]) {
        len++;
        result.push_back(a[i]);
      } else {
        len += 2;
        result.push_back(a[i] == 1 ? a[i] : a[i] - 1);
        result.push_back(a[i]);
      }
    }

    std::cout << len << std::endl;
    for (int i = 0; i < len; i++) {
      std::cout << result[i] << " ";
    }
    std::cout << "\n";
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
