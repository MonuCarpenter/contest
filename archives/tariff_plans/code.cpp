/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 12:09 AM IST
 * Problem: Tarrif Plan
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

/**
3
2
61 10 -> 30: 3*10 + 1*10 => 40 | 2*15 -> 30 + 15 -> 45
3
40 40 40 ->
2
60 65
 * */

class Solution {
public:
  void solve(int ti) {
    auto [t1, t2] = calculate_tarrif();
    std::cout << "Case " << ti << ": "
              << (t1 == t2  ? "Mile Juice"
                  : t1 < t2 ? "Mile"
                            : "Juice")
              << " " << std::min(t1, t2) << std::endl;
  };

private:
  std::pair<int, int> calculate_tarrif() {
    int N;
    std::cin >> N;

    int result = 0;

    int t1 = 0, t2 = 0;

    while (N--) {
      int result;
      std::cin >> result;

      t1 += result / 30;
      t1++;

      t2 += result / 60;
      t2++;
    }
    return {t1 * 10, t2 * 15};
  }
};

int main() {
  // CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  int t;
  std::cin >> t;

  int test_index = 1;
  while (t--) {
    sol.solve(test_index);
    test_index++;
  }

  return 0;
}

// note sure about the third example in the pdf; will do it tomorrow;
