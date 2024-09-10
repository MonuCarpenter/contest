/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 1725961541
 * Problem: 1476/a
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

void solve() {
    int n, k;
    std::cin >> n >> k;

    int remainder = (k - (n % k)) % k;

    int result = 1 + (remainder + n - 1) / n;

    std::cout << result << '\n';
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
