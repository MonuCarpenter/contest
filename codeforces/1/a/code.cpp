/*
 * Author: Monu Carpenter
 * Time: 2024-09-01 01:13:07
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    ll n, m, a;
    std::cin >> n >> m >> a;

    ll down = n % a == 0 ? n / a : (n / a) + 1;
    ll right = m % a == 0 ? m / a : (m / a) + 1;

    std::cout << down * right << "\n";
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
