/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:28 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
private:
  std::unordered_map<char, std::pair<int, int>> values = {
      {'A', {11, 11}}, {'K', {4, 4}},  {'Q', {3, 3}}, {'J', {20, 2}},
      {'T', {10, 10}}, {'9', {14, 0}}, {'8', {0, 0}}, {'7', {0, 0}}};

public:
  int get_value(char rank, bool dominant) {
    auto [dom_val, nondom_val] = values[rank];
    return dominant ? dom_val : nondom_val;
  }
  int get_sum() {
    int n;
    char d;
    std::cin >> n >> d;

    n = n * 4;

    int result = 0;
    while (n--) {
      char ch, dd;
      std::cin >> ch >> dd;

      int value = get_value(ch, d == dd);
      result += value;
    }
    return result;
  }
};

void solve() {
  Solution sol;
  std::cout << sol.get_sum() << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
