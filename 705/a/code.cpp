/*
 * Author: Monu Carpenter
 * Time: 2024-08-08 22:11:23
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
   int n; cin >> n; 

    string result = ""; 
    int i= 0; 
   while(i < n) {
     if(i % 2 ==  0) {
     	result += "I hate"; 
     } else {
     	result += "I love"; 
     }

     if(i == n - 1) {
     	result += " it"; 
     } else {
     	result += " that "; 
     }
     
   	 i++; 
   }

   cout << result << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
