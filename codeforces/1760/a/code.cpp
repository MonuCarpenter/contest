/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: Sep 11 2024 21:11:04
 * Problem: 1760/a
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

void solve() {
    int a[3];

    int i = 0;
    while (i < 3) {
        std::cin >> a[i];
        i++;
    }

    std::sort(a, a + 3);
    std::cout << a[1] << "\n";
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
