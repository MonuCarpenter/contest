/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

/**
 *  if n is divisible by 2 then print -1
 *  else
 *  take 1 to n  and swap them by skipping  2
 *
 */
void solve() {
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << -1 << '\n';
    } else {
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i + 1;
        }

        for (int i = 1; i < n; i += 2)
            std::swap(p[i], p[i + 1]);
        for (int i = 0; i < n; i++)
            std::cout << p[i] << " \n"[i + 1 == n];
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