/*
 * Author: Monu Carpenter
 * Time: 2024-08-24 18:05:06
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    int a[n];
    int _max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (_max < a[i]) _max = a[i];

        std::cin >> a[i];
    }

    int __second_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] == _max) continue;

        if (a[i] > __second_max) {
            __second_max = a[i];
        }
    }

    std::cout << __second_max + 1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // int T; std::cin >> T;

    // while(T--)
    solve();
    return 0;
}
