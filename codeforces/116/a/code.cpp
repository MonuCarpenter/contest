/*
 * Author: Monu Carpenter
 * Time: 2024-07-26 23:46:09
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve() {
   int n; cin >> n; 

   int maxx = 0; 
   int result =  0; 
   while(n--) {
   	 int a, b; cin >> a >> b; 
   	 result -= a; result += b; 
   	 maxx = max(result, maxx); 
   }

   cout << maxx << endl; 
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
