/*
 * Author: Monu Carpenter
 * Time: 2024-07-20 22:45:53
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
   string s1, s2; cin >> s1 >> s2; 

   int result = 0 ;   
   for(int i=0; i<s1.size(); i++) {
   	 char c1 =tolower( s1.at(i)); 
   	 char c2 = tolower(s2.at(i)); 

     int x1 =(int) c1 - '0' 
     int x2 =(int) c2 - '0' ; 

     if(x1 > x2) { 
         result = 1;
         break; 
     }
     if(x1 < x2) {
         result = -1;
         break; 
      };  	 
   }    

   cout << result; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
