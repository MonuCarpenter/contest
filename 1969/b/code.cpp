/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 2024-09-05 20:47:21
 * Problem: 1969/b
**/

/**
 *  Given: 
 *   String of 0's and 1's 
 *  A cyclic shift is 
 *  for ex: s1 s2 ..... sn;
 *  then it will be 
 *   sn, s1, s2, ..... , s(n-1); 
 *   in one operation  you can choose any sub string 
 *  for l to r where 1 < = l <= r ; 
 *  you can do this unlimited times 
 *   sorted in non descending order minimum 
 */

/**
 *  Simplifying this: 
 *  want in ascending order 
 *  take any substring and shift it; 
 */


#include <bits/stdc++.h>
#define _for(n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve() {

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
        solve();

    std::cout.flush();
    return 0;
}
