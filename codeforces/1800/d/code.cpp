/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 1725965194
 * Problem: 1800/d
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

void solve() {
    long long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    long long result = n - 1;

    for (int i = 0; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1]) result--;
    }

    std::cout << result << "\n";
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
