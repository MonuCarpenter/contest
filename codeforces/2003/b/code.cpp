/*
 * Author: Monu Carpenter
 * Time: 2024-08-26 16:59:11
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    int a[n];

    _for(n) std::cin >> a[i];

    std::sort(a, a + n);

    std::cout << a[n / 2] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();
    return 0;
}
