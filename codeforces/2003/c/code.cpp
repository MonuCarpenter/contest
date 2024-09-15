// TODO: solve it later

/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: Sep 11 2024 21:11:04
 * Problem: 2003/c
 */

#include <bits/stdc++.h>

#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

void swap(std::string s, int i, int j) {
    char temp = s[i];
    s[j] = s[i];
    s[i] = temp;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s; // contains the lower case latter only

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            if (s[i] != s[0]) {
                char t = s[i + 1];
                s[i + 1] = s[0];
                s[0] = t;
            } else
                char t = s[i + 1];
            s[i + 1] = s[s.size() - 1];
            s[s.size() - 1] = t;
        }
    }
}

std::cout << s << "\n";
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
