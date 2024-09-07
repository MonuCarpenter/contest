/*
 * Author: Monu Carpenter
 * Time: $(date +"%Y-%m-%d %H:%M:%S")
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;
// delete all the vowels
// insert . before the each consonent
// replace all the uppercase con.. with the corre.. ones

void solve() {
    std::string s;
    std::cin >> s;

    for (char lower_r : s) {
        char r = (char)tolower(lower_r);

        if (r != 'a' && r != 'e' && r != 'i' && r != 'o' && r != 'u' && r != 'y') {
            std::cout << "." << r;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // int T;
    //  std::cin >> T;

    // while (T--)
    solve();

    std::cout.flush();
    return 0;
}
