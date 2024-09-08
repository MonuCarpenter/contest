/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-08 18:07:58
 * Problem: 1955/b
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int n, r, c;
    std::cin >> n >> r >> c;

    int a[n * n];
    int i = 0;
    while (i < n * n) {
        std::cin >> a[i];
        i++;
    }

    int min = std::min_element(a, a + n * n);
    std::cout << min << "\n";
    int b[n*n]; 
    int j=1; 
    b[0] = min; 
    while(j < n*n) {
      b[j] = min + r 
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
