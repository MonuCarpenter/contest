/*
 * Author: Monu Carpenter
 * Time: 2024-08-24 17:47:08
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n;
    int k;
    std::cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int start = 0;
    int end = n - 1;

    while (k) {
        int temp = a[k];
        a[k] = a[end];
        a[end] = temp;

        start++;
        end--;

        k--;
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // int T;
    // std::cin >> T;

    // while (T--)
    solve();
    return 0;
}
