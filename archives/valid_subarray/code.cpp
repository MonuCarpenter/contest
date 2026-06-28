/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:18 PM IST
 * Problem: Valid SubArrays
 * */

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
public:
  int countValidSubarrays(std::vector<int> &nums, int x) {
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i; j < nums.size(); j++) {
        int sum = 0;
        if (i == j) {
          sum += nums[i];
        } else {
          for (int k = i; k <= j; k++) {
            sum += nums[k];
          }
        }

        std::string str = std::to_string(sum);
        if (str[0] == '1' && str[str.size() - 1] == '1') {
          result++;
        }
      }
    }

    return result;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<int> nums = {1, 100, 1};
  int x = 1;

  Solution solve;
  int result = solve.countValidSubarrays(nums, x);

  std::cout << "Result: " << result << std::endl;
  return 0;
}
