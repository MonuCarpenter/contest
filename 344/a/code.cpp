/*
 * Author: Monu Carpenter
 * Time: 2024-07-28 15:37:50
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n; cin >> n; 

   string s = ""; 

   string  x; 
   while(cin >> x) {
   	 s +=  x; 
   }

   n--; 

  for(int i=0; i<s.size() - 1; i++) {
  	if(s[i] == s[i+1]) {
  		n--; 
  	}
  }

  cout << n << endl;; 
    return; 
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
