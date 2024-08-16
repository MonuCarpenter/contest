/*
 * Author: Monu Carpenter
 * Time: 2024-07-23 23:27:50
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int m,n; cin >> m >> n;  
  vector<vector<int>> matrix(m, vector<int>(n)); 
  
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) { 
       cin >> matrix[i][j];
     } 
   }

   if(m ==1 && n == 1) {
  	cout << -1 << endl; 
  	return; 	
  }
  
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      cout << matrix[(i+1)%m][(j+1)%n] << " "; 
     }
    cout << endl; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; 
    cin >> T; 

    while(T--)
    solve();
    
    return 0;
}
