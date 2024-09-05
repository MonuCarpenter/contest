/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-03 20:37:35
 * Problem: 2009/c
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    ll x, y, k;
    std::cin >> x >> y >> k;

    std::cout << (std::ceil
    (x > y ? x : y) / k) * 2 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();

    std::cout.flush();
    return 0;
}
