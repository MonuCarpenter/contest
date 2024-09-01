/*
 * Author: Monu Carpenter
 * Time: 2024-08-10 14:43:13
 **/
#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::cin.ignore();  // To ignore the newline character left in the buffer

    std::string s1;

    std::map<int, int> _map;

    while (std::getline(std::cin, s1)) {
        std::istringstream stream(s1);

        int x;
        while (stream >> x) {
            _map[x]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (_map.count(i) == 0) {
            std::cout << "Oh, my keyboard!";
            return;
        }
    }

    std::cout << "I become the guy.";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
    return 0;
}
