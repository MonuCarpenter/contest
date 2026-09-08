/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:05 PM IST
 * Problem: G
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
    int islandCount;
    std::cin >> islandCount;
    long long limit;
    std::cin >> limit;
    std::vector<long long> height(islandCount);
    for (int idx = 0; idx < islandCount; ++idx) std::cin >> height[idx];

    std::vector<long long> slackPrefix(islandCount, 0);
    for (int idx = 1; idx < islandCount; ++idx) {
      long long gap = height[idx] - height[idx - 1];
      long long slack = limit - gap;
      slackPrefix[idx] = slackPrefix[idx - 1] + slack;
    }

    std::vector<long long> slackPrefixSum(islandCount, 0);
    slackPrefixSum[0] = slackPrefix[0];
    for (int idx = 1; idx < islandCount; ++idx) {
      slackPrefixSum[idx] = slackPrefixSum[idx - 1] + slackPrefix[idx];
    }

    auto rangePrefixSum = [&](int left, int right) -> long long {
      if (left > right) return 0;
      long long total = slackPrefixSum[right];
      if (left > 0) total -= slackPrefixSum[left - 1];
      return total;
    };

    std::vector<long long> answer(islandCount, 0);
    for (int removed = 1; removed + 1 < islandCount; ++removed) {
      long long bridge = height[removed + 1] - height[removed - 1] - limit;
      if (bridge <= 0) {
        answer[removed] = 0;
        continue;
      }
      long long base = slackPrefix[removed + 1];
      long long threshold = base + bridge;
      int lo = removed + 1;
      int hi = islandCount - 1;
      int far = lo;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (slackPrefix[mid] < threshold) {
          far = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      long long span = (long long)far - (removed + 1) + 1;
      long long gathered = rangePrefixSum(removed + 1, far);
      long long accumulatedSlack = gathered - span * base;
      answer[removed] = span * bridge - accumulatedSlack;
    }

    for (int idx = 0; idx < islandCount; ++idx) {
      std::cout << answer[idx] << (idx + 1 == islandCount ? '\n' : ' ');
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
