/*
 * Author: Monu Carpenter
 * Time: 2024-08-04 19:04:08
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
   map<int, int> _map; 

  int x;
  while(cin >> x) { 
   _map[x]++;  
  }

  int result =  0; 
  
  for(auto a: _map) {
     if(a.second > 1) { 
        result +=  a.second - 1;    
    }
  }

  cout << result << endl; 
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
