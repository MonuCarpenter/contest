/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 06:13 PM IST
 * Problem: <problem-name>
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

// take the top 25 cards
// set y = 0;
// then execute these 3 times
// take the top card of the cards and determine its value
// let the card is x then y += x;
// put the card and two 10-x cards away.
// at the last put 25 cards in your hand
//
class Solution {
public:
  int get_card_value(std::string card) {
    char init = card[0];

    std::set<char> numbers = {'2', '3', '4', '5', '6', '7', '8', '9'};
    if (numbers.find(init) != numbers.end()) {
      return init - '0';
    } else {
      return 10;
    }
  }
  void solve() {
    // reading and storaring the first 52 cards
    std::vector<std::string> cards(52);

    for (int i = 0; i < 52; i++) {
      std::cin >> cards[i];
    }

    int Y = 0;
    int pile_top = 26;
    for (int i = 0; i < 3; i++) {
      int val = get_card_value(cards[pile_top]);
      Y += val;
      pile_top -= (10 - val) + 1;
    }

    if (Y <= pile_top + 1) {
      std::cout << cards[Y - 1] << std::endl;
    } else {
      std::cout << cards[27 + Y - (pile_top + 1) - 1] << std::endl;
    }
  }
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  Solution sol;
  for (int cas = 1; cas <= t; cas++) {
    std::cout << "Case " << cas << ": ";
    sol.solve();
  }

  return 0;
}
