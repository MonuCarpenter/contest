/*
 * Author: Monu Carpenter
 * Time: 2024-07-26 22:41:40
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
   string s; cin >> s; 

   int result = 0;

   for(char x: s) {
   	if(x == '4' || x  == '7') result++; 
   }

   cout << ((result == 4 ||  result == 7) ? "YES" : "NO"); 
   return; 
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
