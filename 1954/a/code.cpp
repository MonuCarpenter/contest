/*
 * Author: Monu Carpenter
 * Time: 2024-08-17 11:53:06
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

/**
 *  Alice will paint every part and the Blob will paint at most k part
 *  Alice --> m colors
 *  Blob --> same colors
 *
 */

void solve() {
    ll n, m, k;
    std::cin >> n >> m >> k;

    if (m == 1 || n == 1) {
        std::cout << "NO\n";
        return;
    }

    ll required_multiple = (n * (m - 1)) / m;

    if (n - required_multiple <= k) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
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
