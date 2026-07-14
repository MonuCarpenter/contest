/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 04:18 PM IST
 * Problem: baloni
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using namespace std;

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
private:
  int sum(std::vector<int> &counts) {
    int total = 0;
    for (int count : counts) {
      total += count;
    }
    return total;
  };

public:
  void solve() {
    int n;
    std::cin >> n;
    std::vector<int> counts(n + 2, 0);

    for (int i = 0; i < n; i++) {
      int temp;
      std::cin >> temp;
      if (counts[temp] == 0) {
        counts[temp - 1]++;
      } else {
        counts[temp]--;
        counts[temp - 1]++;
      }
    }

    std::cout << sum(counts) << std::endl;
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
