/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 */

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)
typedef long long ll;

const std::string VOWELS = "aeiou";
const int N = 5;

void solve() {
    int n;
    std::cin >> n;

    std::string answer = "";
    for (int i = 0; i < N; i++) {
        int x = n / (N - i);
        answer += std::string(x, VOWELS[i]);
        n -= x;
    }

    std::cout << answer << "\n";
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