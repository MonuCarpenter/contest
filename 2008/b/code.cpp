/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-01 19:56:13
 * Problem: 2008/b
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;
bool checkMatrix(std::string matrix, int size) {
    int sideLength = sqrt(size);

    if (sideLength * sideLength != size) return false;

    for (int i = 0; i < sideLength; ++i) {
        if (matrix[i] != '1' || matrix[size - sideLength + i] != '1') return false;
    }

    for (int i = 1; i < sideLength - 1; ++i) {
        if (matrix[i * sideLength] != '1' || matrix[i * sideLength + sideLength - 1] != '1') return false;

        for (int j = 1; j < sideLength - 1; ++j) {
            if (matrix[i * sideLength + j] != '0') return false;
        }
    }

    return true;
}

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    if (checkMatrix(s, n)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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
