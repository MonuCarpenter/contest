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

    ll min_sum = x * (x + 1) / 2;
    ll max_sum = n * (n + 1) - (n - x) * (n - x - 1);

    if (k >= min_sum && k <= max_sum) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
