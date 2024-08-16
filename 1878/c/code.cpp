/*
 * Author: Monu Carpenter
 * Time: 2024-08-16 21:11:27
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    ll n, k, x;
    std ::cin >> n >> k >> x;

    ll _sum = k * ((1 + k) / 2);

    for (int i = 1; i < n; i++) {
        int new_sum = _sum + (k + 1 - i);
        if (new_sum == x) {
            std::cout << "YES\n";
        }
    }

    std::cout << "NO\n";    
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
