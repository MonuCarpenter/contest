/*
 * Author: Monu Carpenter
 * Time: 2024-08-27 04:48:22
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    std::string s;
    std::cin >> s;

    std::string result;

    _for(s.size()) {
        if (s[i] == '.') result += '0';
        if (i + 1 != s.size() && s[i] == '-' && s[i + 1] == '.') {
            result += '1';
            i++;
        }
        if (i + 1 != s.size() && s[i] == '-' && s[i + 1] == '-') {
            result += '2';
            i++;
        }
    }

    std::cout << result << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // int T;
    // std::cin >> T;

    // while (T--)
    solve();

    std::cout.flush();
    return 0;
}
