/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 03:36 PM IST
 * Problem: A
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef MONU_LOCAL_JUDGE
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
public:
  void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> freq(2);

    int sum = 0;
    while (n--) {
      int current;
      std::cin >> current;
      a.push_back(current);
      sum += current;
      freq[current == -1 ? 0 : 1]++;
    }

    int result = 0;
    if (sum < 0) {
      result += (1 - sum) / 2;
    }

    if ((freq[0] - result) & 1) {
      result++;
    }

    std::cout << result << "\n";
  }
};
    
int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  Solution sol;
  while (t--) {
    sol.solve();
  }

  return 0;
}
