/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 07:02 PM IST
 * Problem: Annoying the ghost
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifndef ONLINE_JUDGE
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
private:
  void move_j_to_i(std::vector<int> &a, int i, int j) {
    std::rotate(a.begin() + i, a.begin() + j, a.begin() + j + 1);
  }

public:
  void annoy() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      std::cin >> b[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
      bool found = false;
      for (int j = i; j < n; j++) {
        if (a[j] <= b[i]) {
          move_j_to_i(a, i, j);
          result += j - i;
          found = true;
          break;
        }
      }
      if (!found) {
        result = -1;
        break;
      }
    }

    std::cout << result << '\n';
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  Solution solve;
  while (t--) {
    solve.annoy();
  }

  return 0;
}
