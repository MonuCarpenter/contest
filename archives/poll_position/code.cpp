/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 04:31 PM IST
 * Problem: poll positions;
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  std::vector<int> get_positions(std::vector<int> changes) {
    for (int i = 0; i < changes.size(); i++) {
      changes[i] += i;
    }
    return changes;
  }
  void solve(int n) {
    if (n == 0)
      return;

    std::vector<int> poll_indexes;
    std::vector<int> changes;

    while (n--) {
      int index, change;
      std::cin >> index >> change;

      poll_indexes.push_back(index);
      changes.push_back(change);
    }

    std::vector<int> result = get_positions(changes);

    std::vector<int> fr(result.size());

    for (int i = 0; i < result.size(); i++) {
      fr[result[i]] = poll_indexes[i];
    }

    for (int i = 0; i < fr.size(); i++) {
      std::cout << fr[i] << (i == fr.size() - 1 ? '\n' : ' ');
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  int n;

  while (std::cin >> n)
    sol.solve(n);

  return 0;
}
