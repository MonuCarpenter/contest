/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-08 19:29:56
 * Problem: 122/a
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

/**
 *  Question says, divisiable by some lucky numbers
 *  here some is, <= the actual number
 *  here since the n <= 1000
 *  so we can directly check for 4, 7,47,74, 447, etc
 */
void solve() {
    int n;
    std::cin >> n;

    if (n % 4 == 0 || n % 7 == 0 || n % 47 == 0 || n % 74 == 0 || n % 477 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
