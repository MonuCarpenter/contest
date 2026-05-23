/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:20 PM IST
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

/*
3 -> number of participants  1000 -> budget 2 -> number of hotels to consider 3
-> number of weeks
----2 * H --- lines
200 -> price for each at holtel
0 2 2 -> -> empty beds for the weekned
300 -> price
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13
 * */

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int result = 0;
  int n, b, h, w;
  while (std::cin >> n >> b >> h >> w) {
    result = b + 1;
    for (int i = 0; i < h; i++) {
      int p;
      std::cin >> p;
      for (int j = 0; j < w; j++) {
        int a;
        std::cin >> a;
        if (a >= n) {
          result = std::min(result, p * n);
        }
      }
    }
    if (result > b) {
      std::cout << "stay home\n";
    } else {
      std::cout << result << '\n';
    }
  }

  return 0;
}
