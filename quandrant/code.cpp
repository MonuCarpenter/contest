/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:46 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

class Solution {
public:
  int get_quadrant(int x, int y) {
    if (x > 0) {
      if (y > 0)
        return 1;
      return 4;
    } else {
      if (y > 0)
        return 2;
      else
        return 3;
    }
    return 1;
  };
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Solution sol;

  int x, y;
  std::cin >> x >> y;

  std::cout << sol.get_quadrant(x, y) << "\n";

  return 0;
}
