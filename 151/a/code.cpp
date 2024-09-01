/*
 * Author: Monu Carpenter
 * Time: 2024-08-31 18:39:03
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;
// n friends are there
// and they are buying the k bottles
// k -> each has l ml drink
// c -> limes -> d slices
// so
// k*l ml drink
// c*d slices
// p grams of salt
//

// each friend needs
// nl -> ml of drink
// np -> gram of salt
// and a slice to make a drink
//
void solve() {
    int n, k, l, c, d, p, nl, np;
    std::cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink = k * l;
    int slices = c * d;

    int drink_count = drink / nl;
    int salt_count = p / np;

    int result = std::min(std::min(drink_count, salt_count), slices);

    std::cout << result / n << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T = 1;
    // std::cin >> T;

    while (T--)
        solve();

    std::cout.flush();
    return 0;
}
