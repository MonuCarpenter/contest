/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: Sep 11 2024 21:11:04
 * Problem: 520/a
 */

#include <bits/stdc++.h>
#include <cctype>
#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    bool lowerFound = false;
    bool upperFound = false;

    for (char ch : s) {
        if (std::islower(ch))
            lowerFound = true;

        if (std::isupper(ch))
            upperFound = true;
    }

    if (lowerFound && upperFound) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int T;
    //  std::cin >> T;
    // while (T--)
    solve();
    return 0;
}
