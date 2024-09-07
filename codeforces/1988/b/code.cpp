/**
 * Author: Monu Carpenter
 * Time: 2024-08-16 12:48:16
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int one = std::count(s.begin(), s.end(), '1');

    int zeros = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) zeros++;
    }

    if (zeros < one)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
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
