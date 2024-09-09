/*
 * Author: Monu Carpenter
 * Time: 2024-07-26 23:02:19
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
   string s,t; cin >> s >> t; 

   if(s.size() != t.size()) {
   	cout << "NO" << endl; 
   	return; 
   }

   for(int i=0; i<s.size(); i++) {
   	  char x = s.at(s.size() - 1 - i); char y = t.at(i); 
 
       
   	  if(x != y) {
   	  	cout  << "NO" << endl; 
   	  	return; 
   	  }
   	  
   }

   cout << "YES" << endl; 
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
