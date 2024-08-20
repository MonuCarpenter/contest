/*
 * Author: Monu Carpenter
 * Time: 2024-08-18 18:24:31
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n, k;
    std::cin >> n >> k;

    if (n == 1) {
        std::cout << "YES\n";
        return;
    }

    if (n == 2) {
        std::cout << "NO\n";
        return;
    }

    std::string s;
    std::cin >> s;

 
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
