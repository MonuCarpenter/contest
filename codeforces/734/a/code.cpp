/*
 * Author: Monu Carpenter
 * Time: 2024-07-26 22:46:59
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
   int n; cin >> n; 
   string s; cin >> s; 

   int a = 0;
   int d = 0;

   for(char x: s) {
  
   	if(x == 'D') d++; 
   	if(x == 'A') a++; 
   }


      
   if(a == d) {
   	cout <<"Friendship" << endl;
   	return;  
   } 

   if(a > d) {
   	cout << "Anton" << endl;
   	return; 
   }
   if(a < d) {
   	cout << "Danik" << endl; 
   	return; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
