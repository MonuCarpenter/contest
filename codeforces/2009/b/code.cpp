/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-03 20:18:13
 * Problem: 2009/b
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    int result[n];

    int index = 0;

    _for(n) {
        std::string s;
        std::cin >> s;
        _for(s.size()) {
            if (s[i] == '#') {
                result[index] = i + 1;
                index++;
            }
        }
    }

    _for(n) std::cout << result[n - i - 1] << (i == n - 1 ? "\n" : " ");
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
