/*
 * Author: Monu Carpenter
 * Time: 2024-07-22 22:47:35
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int x, y; cin >> x >> y; 

    int i=0;

    while(true) {
    	x *= 3;
    	y *= 2; 

       if( x > y) {
       	cout  << i+1 <<  endl; 
       	break; 
       } 
       i++; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
