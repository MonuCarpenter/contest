/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 03:31 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  void back_to_school() {
    int x, y;

    while (std::cin >> x && std::cin >> y) {
      int result = x * y * 2;
      std::cout << result << std::endl;
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  sol.back_to_school();
  return 0;
}
