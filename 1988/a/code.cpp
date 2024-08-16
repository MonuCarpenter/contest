/*
 * Author: Monu Carpenter
 * Time: 2024-08-16 17:58:26
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    double n, k;
    std::cin >> n >> k;

    if (n == 1) {
        std::cout << "0\n";
    } else {
        std::cout << std::ceil((n - 1) / (k - 1)) << "\n";
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
