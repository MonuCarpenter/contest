/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 06:27 PM IST
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
private:
  // returns 1 for increasing, -1 for decreasing and 0 for equal
  int check_order(std::string a, std::string b) {
    if (a < b) {
      return 1;
    } else if (a > b) {
      return 2;
    } else {
      return 0;
    }
  }
  std::string line_up(int n) {
    bool inc = false;
    bool desc = false;

    std::vector<std::string> inputs;

    while (n--) {
      std::string s;
      std::cin >> s;
      inputs.push_back(s);
    }

    for (int i = 0; i < inputs.size() - 1; i++) {
      // we will checkfor the alphabetical order of the strings
      if (check_order(inputs[i], inputs[i + 1]) == 1) {
        inc = true;
      } else if (check_order(inputs[i], inputs[i + 1]) == 2) {
        desc = true;
      }
    }

    if (inc && desc || (!inc && !desc)) {
      return "NEITHER";
    } else if (inc) {
      return "INCREASING";
    } else {
      return "DECREASING";
    }
  }

public:
  void solve() {
    int n;
    std::cin >> n;

    std::cout << line_up(n) << "\n";
  }
};
int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;
  sol.solve();

  return 0;
}
