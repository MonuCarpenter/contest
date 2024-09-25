/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    std::cin >> n;

    if (n & 1) {
        std::cout << -1 << "\n";
    } else {
        std::cout << 1 << " " << n / 2 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}