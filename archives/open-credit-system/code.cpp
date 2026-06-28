/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 11:18 AM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  int calculate(int n) {
    std::vector<int> digits;

    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      digits.push_back(x);
    }

    if (digits[0] > digits[1]) {
      return digits[0] - digits[n - 1];
    } else {
      return digits[0] - digits[1];
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution solution;

  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::cout << solution.calculate(n) << "\n";
  }

  return 0;
}
