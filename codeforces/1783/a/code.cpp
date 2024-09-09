/*
 * Author: Monu Carpenter
 * Time: 2024-08-31 17:17:13
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

    bool flag = false;

    _for(n) {
        int sum = 0;
        for (int j = 0; j < i; i++) {
            sum += a[j];
        }
        if (sum == a[i]) flag = true;
    }

    if (flag) {
        std::cout << "YES\n";
        _for(n) {
            a[i] + (i == n - 1 ? "\n" : " ");
        }
    } else {
        std::cout << "NO\n";
    }
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
