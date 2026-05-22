/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 05:00 PM IST
 * Problem: ACM Contest Scoring
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
  std::pair<int, int> calculate_scores() {
    int score = 0;
    int solved_problems = 0;

    int n;
    char a;
    std::string decision;

    struct Input {
      int n;
      char a;
      std::string s;
    };

    std::vector<Input> inputs;

    while (std::cin >> n >> a >> decision) {
      if (n == -1)
        break;

      inputs.push_back({n, a, decision});
    }

    std::map<char, bool> rights;

    for (auto [n, a, decision] : inputs) {
      if (decision == "right")
        rights[a] = true;
    }

    for (auto [n, a, decision] : inputs) {
      if (decision == "wrong" && rights[a]) {
        score += 20;
      } else if (decision == "right") {
        solved_problems++;
        score += n;
      }
    }
    return {solved_problems, score};
  };
  void solve() {
    auto [solved_problems, score] = calculate_scores();
    std::cout << solved_problems << " " << score << "\n";
  };
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution solution;
  solution.solve();

  return 0;
}
