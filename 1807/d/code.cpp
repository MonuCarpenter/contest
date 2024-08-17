/*
 * Author: Monu Carpenter
 * Time: 2024-08-17 13:11:56
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n, q;
    std::cin >> n >> q;

    int a[n];
    while (q--) {
        int l, r, k;

        ll sum_till_l = 0;
        ll sum_till_r_to_n = 0;

        for (int i = 0; i < l - 1; i++) {
            sum_till_l += a[i];
        }

        for (int i = r - 1; i < n; i++) {
            sum_till_r_to_n += a[i];
        }

        if ((sum_till_l + sum_till_r_to_n + k) % 2 != 0) {
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
