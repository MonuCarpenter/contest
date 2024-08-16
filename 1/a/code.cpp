/*
 * Author: Monu Carpenter
 * Time: 2024-08-16 01:02:33
 * Handle: m_o_n_u
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int x;
    cin >> x;
    if (x) {
        x++;
    }

    if (x) {
        if (x++) x;
    }
    if (x == 0) x++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
