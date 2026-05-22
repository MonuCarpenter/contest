/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:52 PM IST
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
/*
3 -> kinds of tea
10 20 30 -> prices of the tea
5 -> amount of toppings the shop has
1 2 3 4 5 -> price of all the toppings
------- n lines starts here ----
2 4 5 -> can be mixed with 1 st tea
3 1 2 3
5 1 2 3 4 5
------- n lines ends here
42
 * */
class Solution {
private:
  int max_tea() {
    int n;
    std::cin >> n;

    std::vector<int> kinds_of_tea(n);
    for (int i = 0; i < n; i++) {
      std::cin >> kinds_of_tea[i];
    }

    int t;
    std::cin >> t;
    std::vector<int> toppings(t);
    for (int i = 0; i < t; i++) {
      std::cin >> toppings[i];
    }

    std::vector<int> tea_prices;

    for (int i = 0; i < n; i++) {
      int tn;
      std::cin >> tn;

      int price = kinds_of_tea[i];
      for (int j = 0; j < tn; j++) {
        int x;
        std::cin >> x;
        tea_prices.push_back(price + x);
      }
    }

    std::sort(tea_prices.begin(), tea_prices.end());

    int mn;
    std::cin >> mn;

    int max_tea = 0;

    for (const auto price : tea_prices) {
      max_tea = std::max(max_tea, mn / price);
    }

    return max_tea;
  };

public:
  void solve() { std::cout << max_tea() - 1 << "\n"; };
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;
  sol.solve();

  return 0;
}
