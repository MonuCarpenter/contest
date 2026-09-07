/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 06:12 PM IST
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
public:
  void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    bool is_all_same = true;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[0]) {
        is_all_same = false;
        break;
      }
    }

    if (is_all_same) {
      std::cout << -1 << std::endl;
      return;
    }

    int cnt = 0;
    for (int x : a)
      if (x == a.back())
        cnt++;

    std::cout << n - cnt << " " << cnt << std::endl;

    for (int x : a)
      if (x != a.back())
        std::cout << x << " ";
    std::cout << "\n";

    for (int i = 0; i < cnt; i++)
      std::cout << a.back() << " ";
    std::cout << "\n";
    return;
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
