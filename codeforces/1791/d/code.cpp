/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-01 17:09:56
 * Problem: 1791/d
 **/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> charCount(26, 0), prefixCount(26, 0);
    for (char c : s) {
        charCount[c - 'a']++;
    }
    int maxDistinctChars = 0;
    for (char c : s) {
        charCount[c - 'a']--;
        prefixCount[c - 'a']++;
        int currentDistinctChars = 0;
        for (int i = 0; i < 26; ++i) {
            currentDistinctChars += std::min(1, charCount[i]) + std::min(1, prefixCount[i]);
        }
        maxDistinctChars = std::max(maxDistinctChars, currentDistinctChars);
    }
    std::cout << maxDistinctChars << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}
