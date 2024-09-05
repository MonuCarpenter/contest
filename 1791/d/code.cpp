/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-01 17:09:56
 * Problem: 1791/d
 **/

#include <bits/stdc++.h>
#define _for(s, n) for (int i = s; i < n; i++)

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    char a[n];

    _for(0, n) std::cin >> a[i];

    std::map<char, int> _map;

    _for(0, n) _map[a[i]]++;

    int result = 0;
    int flag = false;
    for (auto x : _map) {
        if (x.second > 0) result++;
        if (x.second > 1) flag = true;
    }
    std::cout << (flag ? ++result : result) << "\n";
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
