/*
 * Author: Monu Carpenter
 * Time: 2024-08-15 23:34:55
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50;

void solve() {
    int n;
    int q[N];
    cin >> n;

    for (int i = 1; i <= n; ++i) q[i] = 0;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ++q[x];
    }

    for (int i = 1; i <= n; ++i) {
        if (q[i] % 2 == 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();
    return 0;
}
