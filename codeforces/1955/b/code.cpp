/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-08 18:07:58
 * Problem: 1955/b
 **/

/**
 *  My approach
 *  - Generate the matrix
 *  - Push into a 1D array
 *  - Sort the 1D array
 *  - sort the given and compare both array
 *  - return true if they are same else false
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int n, r, c;
    std::cin >> n >> r >> c;

    std::vector<int> given(n * n);
    for (int i = 0; i < n * n; ++i) {
        std::cin >> given[i];
    }
    std::sort(given.begin(), given.end());

    std::vector<int> created;
    _for(n) {
        for (int j = 0; j < n; j++) {
            created.push_back(given[0] + c * i + r * j);
        }
    }

    std::sort(created.begin(), created.end());

    if (given == created) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();

    return 0;
}
