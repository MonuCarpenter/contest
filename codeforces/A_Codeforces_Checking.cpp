/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

const std::string C = "codeforces";

void solve() {
    char ch;
    std::cin >> ch;

    for (int i = 0; i < C.size(); i++) {
        if (ch == C[i]) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
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