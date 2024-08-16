/*
 * Author: Monu Carpenter
 * Time: 2024-07-26 23:55:52
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
   int n, h; cin >> n >> h; 

   int result = 0; 
   while(n--) {
    int x; cin >> x; 
   	if(x > h) result += 2;
   	else 
   	result++; 
   }

   cout << result << endl; 
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
