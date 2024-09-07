/*
 * Author: Monu Carpenter
 * Time: 2024-08-14 01:14:19
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;

    string s = to_string(n);

    if(n < 102) {
        cout << "NO" << endl;
        return;
    }

    int powL =   stoi(s.substr(2, s.size() - 1));
    if(s[0] != '1' || s[1] != '0' || s[2] == '0' ||  powL < 2) {
        cout << "NO" << endl;
    }  else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin  >> T;

    while(T--)
    solve();
    return 0;
}

//
