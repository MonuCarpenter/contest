/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-07 20:04:45
 * Problem: tlx/38/a
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int x;
    int maxP = 0;
    int maxN = 0;

    std::cin >> maxP;

    while (std::cin >> x) {
        if (x <= 0)
            maxN += x;
        else
            maxP += x;
    }

    std::cout << maxP - maxN << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // int T;
    //  std::cin >> T;

    //  while (T--)
    solve();

    std::cout.flush();
    return 0;
}
