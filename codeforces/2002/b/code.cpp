/*
 * Author: Monu Carpenter
 * Time: $(date +"%Y-%m-%d %H:%M:%S")
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> v1;
    std::vector<int> v2;

    _for(n) {
        int x;
        std::cin >> x;
        v1.push_back(x);
    }

    _for(n) {
        int y;
        std::cin >> y;
        v2.push_back(y);
    }

    if (v1 == v2) {
        std::cout << "Bob\n";
        return;
    }

    std::reverse(v2.begin(), v2.end());

    if (v1 == v2) {
        std::cout << "Bob\n";
        return;
    }

    std::cout << "Alice\n";
    return;
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
