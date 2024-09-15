/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 1726142803
 * Problem: 1942/a
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

void solve() {
    int n, k;
    std::cin >> n >> k;

    if (k == n)
        _for(n) std::cout << 1 << " ";
    else if (k == 1)
        _for(n) std::cout << i + 1 << " ";
    else
        std::cout << "-1";

    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}
