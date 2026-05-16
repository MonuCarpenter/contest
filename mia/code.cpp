/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 12:31 AM IST
 * Problem: Mia.
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

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
  void mia(int s0, int s1, int r0, int r1) {
    bool p1_mia = (s0 == 1 && s1 == 2) || (s0 == 2 && s1 == 1);
    bool p2_mia = (r0 == 1 && r1 == 2) || (r0 == 2 && r1 == 1);

    if (p1_mia && p2_mia) {
      std::cout << "Tie.\n";
    } else if (p1_mia) {
      std::cout << "Player 1 wins.\n";
    } else if (p2_mia) {
      std::cout << "Player 2 wins.\n";
    } else if (s0 == r0 && s1 == r1 || s0 == r1 && s1 == r0) {
      std::cout << "Tie.\n";
    } else {
      // we will form the number by highest first digit;
      int first_digit = std::max(s0, s1) * 10 + std::min(s0, s1);
      int last_digit = std::max(r0, r1) * 10 + std::min(r0, r1);

      bool is_first_double = s0 == s1;
      bool is_last_double = r0 == r1;
      if (is_first_double && !is_last_double) {
        std::cout << "Player 1 wins.\n";
        return;
      } else if (!is_first_double && is_last_double) {
        std::cout << "Player 2 wins.\n";
        return;
      }

      if (first_digit > last_digit) {
        std::cout << "Player 1 wins.\n";
      } else if (first_digit < last_digit) {
        std::cout << "Player 2 wins.\n";
      } else {
        std::cout << "Tie.\n";
      }
    }
  };
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int s0, s1, r0, r1;

  Solution sol;

  while (std::cin >> s0 >> s1 >> r0 >> r1) {
    if (s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0) {
      break;
    }
    sol.mia(s0, s1, r0, r1);
  }

  return 0;
}
