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

    ll min_sum = (k * (k + 1)) / 2;
    ll max_sum = (n * (n + 1)) / 2;
    ll temp = ((n - k) * (n - k + 1)) / 2;

    if (x >= min_sum && x <= max_sum - temp) {
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
