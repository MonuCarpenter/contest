/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 05:36 PM IST
 * Problem: Fastfood
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  void fastfood() {
    int n, m;
    std::cin >> n >> m;

    int sn = n;
    int mn = m;
    // n -> number of dff types of pizzas
    // m -> number of dif types of stickers

    std::vector<std::vector<int>> stickers;
    std::vector<int> csc;

    while (n--) {
      int k;
      std::cin >> k;

      std::vector<int> temp(k + 1);
      for (int i = 0; i <= k; i++) {
        int tt;
        std::cin >> tt;
        temp[i] = tt;
      }
      stickers.push_back(temp);
    }

    while (m--) {
      int dd;
      std::cin >> dd;
      csc.push_back(dd);
    }

    int result = 0;

    for (int i = 0; i < sn; i++) {
      int min = INT_MAX;

      for (int ii = 0; ii < stickers[i].size() - 1; ii++) {
        int item = stickers[i][ii];

        int rr = csc[item - 1];
        if (rr < min) {
          min = rr;
        }
      }

      result += min * stickers[i][stickers[i].size() - 1];
    }

    std::cout << result << "\n";
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  Solution sol;

  while (t--) {
    sol.fastfood();
  }

  return 0;
}
