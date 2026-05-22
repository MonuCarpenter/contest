/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 05:54 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
//
// #ifndef ONLINE_JUDGE
// #include "../cpp-dump/cpp-dump.hpp"
// #define log(...) cpp_dump(__VA_ARGS__)
// template <> inline void cpp_dump::write_log(std::string_view output) {
//   std::cout << output << '\n';
// }
// #else
// #define log(...)
// #define CPP_DUMP_SET_OPTION(...)
// #define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
// #define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
// #define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
// #define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
// #endif

class Solution {
public:
  int cetiri() {
    std::vector<int> arr(3);

    for (int i = 0; i < 3; i++) {
      std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    int difference = arr[1] - arr[0];

    if (arr[1] + difference == arr[2]) {
      return arr[2] + difference;
    } else {
      return arr[1] + difference;
    }
  };
  void solve() { std::cout << cetiri() << "\n"; };
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution c_sol;
  c_sol.solve();

  return 0;
}
