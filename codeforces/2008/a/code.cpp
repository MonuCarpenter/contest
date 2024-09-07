/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-01 19:55:49
 * Problem: 2008/a
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (a % 2 == 0) {
        if (b % 2 == 0 || (a >= 2 && b % 2 == 1)) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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
