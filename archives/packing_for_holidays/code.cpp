/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 02:22 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  bool is_good(int l, int w, int h) { return l <= 20 && w <= 20 && h <= 20; };
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  for (int i = 1; i <= t; i++) {
    int l, w, h;
    std::cin >> l >> w >> h;

    Solution sol;
    std::cout << "Case " << i << ": " << (sol.is_good(l, w, h) ? "good" : "bad")
              << "\n";
  }
  return 0;
}
