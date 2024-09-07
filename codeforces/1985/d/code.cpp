/*
 * Author: Monu Carpenter
 * Time: 2024-08-16 18:43:41
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string a[n];

    int _i = -1;
    int max_i = -1;

    for (int i = 0; i < n; i++) {
        std::string line;
        std::cin >> line;
        a[i] = line;
        int hash_count = std::count(line.begin(), line.end(), '#');
        if (hash_count > max_i) {
            max_i = hash_count;
            _i = i;
        }
    }
    // Now we will find the _j

    std::string line = a[_i];

    int start = 0;
    int end = line.size() - 1;

    while (start <= end) {
        if (line[start] == '#' && line[end] == '#') break;

        if (line[start] != '#') start++;
        if (line[end] != '#') end--;
    }

    std::cout << _i + 1 << " " << ((end + start) / 2) + 1 << "\n";
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
