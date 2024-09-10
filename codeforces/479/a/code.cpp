/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-08 20:18:22
 * Problem: 479/a
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int arr[5];
    arr[0] = a + b * c;
    arr[1] = a * (b + c);
    arr[2] = a * b * c;
    arr[3] = (a + b) * c;
    arr[4] = a + b + c;

    int max = *std::max_element(arr, arr + 5);
    std::cout << max << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // int T;
    // std::cin >> T;

    // while (T--)
    solve();

    return 0;
}
