/*
 * Author: Monu Carpenter
 * Time: 2024-08-17 13:11:56
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    ll n, q, pre[200005];

    pre[0] = 0;

    std::cin >> n >> q;

    int a[n];

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    while (q--) {
        ll l, r, k;
        std::cin >> l >> r >> k;

        ll _cal = (pre[n] - (pre[r] - pre[l - 1]) + ((r - l + 1) * k));

        if (_cal % 2 == 1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
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
