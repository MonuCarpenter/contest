/*
 * Author: Monu Carpenter
 * Time: 2024-07-22 22:37:35
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  vector<int> vv;

  int x; 
  while(cin >> x) {
  	vv.push_back(x); 
  }

  sort(vv.begin(), vv.end()); 

  for(int i=0; i<vv.size(); i++) {
  	cout << vv[i] << (i == vv.size() -1 ? '\n' : '+' ) ; 
  }  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
