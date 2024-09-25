/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    std::cin >> n;

    int a[n];

    _for(n) std::cin >> a[i];

    std::sort(a, a + n);

    int total_sum = 0;
    _for(n) total_sum += a[i];

    int _required = total_sum / 2;

    int coins = 0;

    int current = 0;

    _for(n) {
        if (current > _required) break;
        coins++;
        current += a[i];
    }

    std::cout << coins << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

   // int t;
   // std::cin >> t;

   // while (t--) {
        solve();
   // }

    return 0;
}