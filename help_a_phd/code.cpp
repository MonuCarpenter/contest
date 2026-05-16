/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 04:18 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  void solve() {
    std::string s;
    std::getline(std::cin, s);

    if (s == "P=NP") {
      std::cout << "skipped" << "\n";
    } else {
      std::istringstream iss(s);

      int x, y;
      char c;

      iss >> x >> c >> y;

      std::cout << x + y << "\n";
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  std::cin.ignore();

  Solution sol;

  while (t--) {
    sol.solve();
  }

  return 0;
}
