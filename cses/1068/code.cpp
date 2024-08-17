/*
 * Author: Monu Carpenter
 * Time: 2024-08-17 20:36:44
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

// n is odd -> multi by 3 and add one
// n is even then divide by two

void solve(int& x) {
    if (x == 1) return;

    if (x & 1) {
        x = x * 3 + 1;
    } else {
        x = x / 2;
    }
    std::cout << x << " ";
    solve(x);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int x;
    std::cin >> x;

    std::cout << x << " ";

    solve(x);
    return 0;
}
