/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 05:11 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  void statistics(int n, int test_cases) {
    int Max = INT_MIN, Min = INT_MAX;
    while (n--) {
      int x;
      std::cin >> x;

      if (x > Max) {
        Max = x;
      }

      if (x < Min) {
        Min = x;
      }
    }

    std::cout << "Case" << " " << test_cases << ": " << Min << " " << Max << " "
              << Max - Min << "\n";
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;

  int test_cases = 1;

  Solution sol;

  while (std::cin >> n) {
    sol.statistics(n, test_cases);
    test_cases++;
  }
  return 0;
}
