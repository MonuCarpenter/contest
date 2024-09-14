/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: Sep 11 2024 21:11:04
 * Problem: 1828/a
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        int i = 2;
        while (n--) {
            std::cout << i << " ";
            i += 2;
            n--;
        }
    } else {
        int i = 1;
        while (n--) {
            std::cout << i << " ";
            i++;
            n--;
        }
    }
    std::cout << "\n";
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
