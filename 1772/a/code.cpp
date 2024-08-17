/*
 * Author: Monu Carpenter
 * Time: 2024-08-17 19:35:45
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int result = 0;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') continue;

        result += s[i] - '0';
    }

    std::cout << result << "\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();
    return 0;
}
