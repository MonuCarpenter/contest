/*
 * Author: Monu Carpenter
 * Time: 2024-08-17 16:37:10
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

/**
 *  1 to n lamps all the off
 *  OP -
 *  1. choose non-adjacent elements and turn them on [ choose two ]
 *
 */
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int ones_count = std::count(s.begin(), s.end(), '1');

    if (ones_count % 2 != 0) {
        std::cout << "NO\n";
        return;
    }

    if (ones_count == 2) {
        for (int i = 0; (i + 1) < n; i++) {
            if (s[i] == '1' && s[i + 1] == '1') {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
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
