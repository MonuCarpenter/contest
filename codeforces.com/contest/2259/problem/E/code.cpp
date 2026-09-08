/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:20 PM IST
 * Problem: E
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
    int length;
    std::cin >> length;
    std::vector<long long> chart(length);
    for (int idx = 0; idx < length; ++idx) std::cin >> chart[idx];

    bool fixedSeen = false;
    for (int idx = 0; idx < length; ++idx) {
      if (chart[idx] != -1) fixedSeen = true;
    }
    if (!fixedSeen) {
      std::string plain(length, '1');
      std::cout << plain << '\n';
      return;
    }

    std::vector<int> cover(length + 1, 0);
    for (int idx = 0; idx < length; ++idx) {
      if (chart[idx] > 0) {
        int left = idx - (int)chart[idx] + 1;
        int right = idx + (int)chart[idx] - 1;
        if (left < 0) left = 0;
        if (right >= length) right = length - 1;
        if (left <= right) {
          cover[left] += 1;
          cover[right + 1] -= 1;
        }
      }
    }
    std::vector<int> blocked(length, 0);
    int running = 0;
    for (int idx = 0; idx < length; ++idx) {
      running += cover[idx];
      blocked[idx] = (running > 0);
    }
    for (int idx = 0; idx < length; ++idx) {
      if (chart[idx] == 0 && blocked[idx]) {
        std::cout << -1 << '\n';
        return;
      }
    }
    for (int idx = 0; idx < length; ++idx) {
      if (chart[idx] > 0) {
        long long reach = chart[idx];
        int leftSpot = idx - (int)reach;
        int rightSpot = idx + (int)reach;
        bool leftOpen = (leftSpot >= 0 && !blocked[leftSpot]);
        bool rightOpen = (rightSpot < length && !blocked[rightSpot]);
        if (!leftOpen && !rightOpen) {
          std::cout << -1 << '\n';
          return;
        }
      }
    }
    std::string raised;
    raised.reserve(length);
    for (int idx = 0; idx < length; ++idx) {
      raised.push_back(blocked[idx] ? '0' : '1');
    }
    bool anyRaised = false;
    for (char bit : raised) if (bit == '1') anyRaised = true;
    if (!anyRaised) {
      std::cout << -1 << '\n';
      return;
    }
    std::cout << raised << '\n';
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
