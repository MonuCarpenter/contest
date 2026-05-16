/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 04:50 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  void solve(int sweets, int jars) {
    if (jars == 0 && sweets == 0) {
      // do nothing;
    } else if (sweets + jars == 13) {
      std::cout << "Never speak again.\n";
    } else if (jars > sweets) {
      std::cout << "Left beehind.\n";
    } else if (sweets > jars) {
      std::cout << "To the convention.\n";
    } else if (sweets == jars) {
      std::cout << "Undecided.\n";
    };
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  int sweets, jars;

  while (std::cin >> sweets >> jars) {
    sol.solve(sweets, jars);
  }

  return 0;
}
