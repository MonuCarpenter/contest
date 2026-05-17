/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 03:02 PM IST
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

class Solution {
public:
  double find_max_decline() {
    int p, a, b, c, d, n;
    std::cin >> p >> a >> b >> c >> d >> n;

    std::vector<double> prices(n);

    for (int i = 1; i <= n; i++) {
      prices[i - 1] =
          (double)p * (std::sin(a * i + b) + std::cos(c * i + d) + 2);
    }

    double max_decline = 0.0;
    double max_price = prices[0];

    for (int i = 1; i < n; i++) {
      max_price = std::max(max_price, prices[i]);
      max_decline = std::max(max_decline, max_price - prices[i]);
    }

    return max_decline;
  }
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution solution;

  std::cout << std::fixed << std::setprecision(9) << solution.find_max_decline() << '\n';
  return 0;
}
