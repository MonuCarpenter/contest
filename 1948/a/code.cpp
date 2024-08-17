/*
 * Author: Monu Carpenter
 * Time: 2024-08-17 19:22:14
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    if (n % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
    for (int i = 0; i < n / 2; i += 2)
        for (int j = 0; j < 2; ++j)
            std::cout << "AB"[i & 1];
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();
    return 0;
}
