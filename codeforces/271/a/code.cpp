/*
 * Author: Monu Carpenter
 * Time: 2024-07-27 11:56:36
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 bool is_unique(int number) {
 	char seen[10]  = {0}; 

 	while(number) {
 		int digit = number % 10; 
 		number /= 10; 

 		if(seen[digit]++) return false;
 	}

 	return true; 
 } 
 
 void solve() {
   int n ; cin >> n; 
   while(n++) {
     bool unique = is_unique(n); 
     if(unique) {
     	cout << n << endl;
     	return; 
     }
   }
   return; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
