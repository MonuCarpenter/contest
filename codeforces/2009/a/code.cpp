/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-03 20:12:07
 * Problem: 2009/a
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;
//(𝑐−𝑎)+(𝑏−𝑐) = x
// c - a + b - c =  x
// b - a = x
//
void solve() {
    int a, b;
    std::cin >> a >> b;

    std::cout << (b - a) << "\n";
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
