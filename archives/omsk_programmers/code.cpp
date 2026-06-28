/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 09:15 PM IST
 * Problem: <problem-name>
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
public:
  int solve() {
    int a, b, x;
    std::cin >> a >> b >> x;

    int count = 0;
    int result = std::abs(a - b);

    while (a || b) {
      if (a > b) {
        a /= x;
      } else {
        b /= x;
      }
      count++;
      result = std::min(result, count + std::abs(a - b));
    }
    return result;
    // int a, b, x;
    // std::cin >> a >> b >> x;
    //
    // int answer = std::abs(a - b);
    //
    // int c = 0;
    // while (a || b) {
    //   if (a > b) {
    //     a /= x;
    //   } else {
    //     b /= x;
    //   }
    //   c++;
    //   answer = std::min(answer, std::abs(a - b) + c);
    // }
    // return answer;
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
    std::cout << sol.solve() << std::endl;
  }

  return 0;
}
