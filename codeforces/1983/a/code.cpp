/*
 * Author: Monu Carpenter
 * Time: 2024-07-20 01:41:15
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cout << i + 1 << (i < n - 1 ? " " : "\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();
    return 0;
}
