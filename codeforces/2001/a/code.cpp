/*
 * Author: Monu Carpenter
 * Time: 2024-08-20 20:13:37
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>

typedef long long ll;

// need to make the elements same
// Logic: find the element with highest frequency;

void solve() {
    int n;
    std::cin >> n;

    int a[n];
    // taking the inputs for the array;
    for (int i = 0; i < n; i++) std::cin >> a[i];

    if (n == 1) {
        std::cout << 0 << "\n";
        return;
    }

    std::map<int, int> _map;

    for (int i = 0; i < n; i++) {
        if (_map.count(a[i]) > 0) {
            _map[a[i]]++;
        } else {
            _map[a[i]] = 1;
        }
    }

    int freq = INT_MIN;

    for (auto& e : _map) {
        if (e.second > freq) {
            freq = e.second;
        }
    }

    std::cout << n - freq << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();
    return 0;
}
