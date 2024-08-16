/*
 * Author: Monu Carpenter
 * Time: 2024-08-16 18:43:41
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    std::string a[n];

    int _i = -1;
    int max_i = -1;

    for (int i = 0; i < n; i++) {
        std::string line;
        cin >> line;
        a[i] = line;
        int hash_count = std::count(line.begin(), line.end(), '#');
        if (hash_count > max_i) {
            max_i = hash_count;
            _i = i;
        }
    }

    std::cout << "---> " << a[_i] << std::endl;
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
