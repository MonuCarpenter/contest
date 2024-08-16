/*
 * Author: Monu Carpenter
 * Time: 2024-07-19 01:01:48
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n; cin >> n ; 
  string s; cin >> s; 
  int result = 0;
  for(int i=0; i+1<n; i++) 
  if(s[i] == s[i+1]) result++; 

  cout << result << endl; 
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
