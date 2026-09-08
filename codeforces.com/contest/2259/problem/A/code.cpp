/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 08:17 PM IST
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
    // n -> fields
    // k -> n / k farms
    // n is the multiple of k
    // k consecutive fields -> each form
    // ith field is in i/k (th) farm

    int n, k;
    std::cin >> n >> k;
    std::string str;
    std::cin >> str;

    std::vector<int> freq(n / k, 0);
    int start = 0;
    while (start < n) {
      if (str[start] == '0') {
        freq[start / k] = 1;
        start = (start / k + 1) * k;
      } else {
        start++;
      }
    }

    int check = 0;
    for (int f : freq)
      if (f == 0)
        check++;

    std::cout << check << std::endl;
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
