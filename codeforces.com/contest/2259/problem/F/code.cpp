/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:12 PM IST
 * Problem: F
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
    std::vector<int> badge(length);
    for (int idx = 0; idx < length; ++idx) std::cin >> badge[idx];
    std::string order;
    std::cin >> order;

    std::vector<long long> backlog;
    backlog.reserve(length);
    int seenZero = 0;
    for (int idx = 0; idx < length; ++idx) {
      if (badge[idx] == 0) {
        backlog.push_back((long long)idx - seenZero);
        ++seenZero;
      }
    }
    int zeroTotal = (int)backlog.size();
    std::vector<long long> backlogSum(zeroTotal, 0);
    for (int idx = 0; idx < zeroTotal; ++idx) {
      backlogSum[idx] = backlog[idx] + (idx ? backlogSum[idx - 1] : 0);
    }

    auto currentInversions = [&](int forwardDone, int reverseDone) -> long long {
      int alive = zeroTotal - reverseDone;
      if (alive <= 0) return 0;
      if (alive > zeroTotal) alive = zeroTotal;
      int pos = std::upper_bound(backlog.begin(), backlog.begin() + alive, (long long)forwardDone) - backlog.begin();
      if (pos >= alive) return 0;
      long long gathered = backlogSum[alive - 1] - (pos ? backlogSum[pos - 1] : 0);
      return gathered - (long long)(alive - pos) * forwardDone;
    };

    int forwardDone = 0;
    int reverseDone = 0;
    for (int step = 0; step <= length; ++step) {
      std::cout << currentInversions(forwardDone, reverseDone) << (step == length ? '\n' : ' ');
      if (step < length) {
        if (order[step] == '1') ++forwardDone;
        else ++reverseDone;
      }
    }
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
