/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: Sep 11 2024 21:11:04
 * Problem: 2005/a
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    std::string s = "aeiou";

    if (n < 6) {
        s = s.substr(0, n);
    } else {
        s += s.substr(0, n - 5);
    }

    std::cout << s << "\n";
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
