/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 08:40 AM IST
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

typedef std::tuple<int, int, int> tiii;
typedef std::vector<tiii> vtiii;

class Solution {
public:
  void solve() {
    int test_cases;
    std::cin >> test_cases;
    while (test_cases--) {
      int N;
      std::cin >> N;

      if (N == 0) {
        break;
      }

      vtiii divs = division(N);

      for (auto [a, b, c] : divs) {
        if (a == 0 && b == 0 && c == 0 && divs.size() == 1) {
          std::cout << "There are no solutions for " << N << ".\n";
        } else {
          if (a == 0 && b == 0 && c == 0)
            std::cout << std::endl;
          else
            std::cout << a << " / " << b << " = " << c << "\n";
        }
      }
    }
  }
  vtiii division(int N) {
    vtiii results = {{0, 0, 0}};

    for (int fghij = 12345; fghij <= 98765; fghij++) {
      int abcde = fghij * N;
      if (abcde > 98765)
        break;

      std::string s1 = std::to_string(fghij);
      std::string s2 = std::to_string(abcde);

      std::set<char> digits;
      for (char c : s1)
        digits.insert(c);
      for (char c : s2)
        digits.insert(c);

      if (digits.size() == 10 && digits.find('0') == digits.end()) {
        results.push_back({abcde, fghij, N});
      }
    }
    return results;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution solution;
  solution.solve();

  return 0;
}
