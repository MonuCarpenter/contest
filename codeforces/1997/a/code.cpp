/*
 * Author: Monu Carpenter
 * Time: 2024-08-03 21:13:26
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// current password/ 
// -> string and lowercase lattin laters 
// -> too weak; 
// -> want to make it more strong 
// -> one latter he wants to add  
// -> He can choose any char and insert it anywhere.. 
// -> strength is prepotional to time 
// ->> and time is dependent on the fol... 
// -> 
 // - FIrst == 2 seconds 
 // - Other than the first == 
             // if it is same the prev - 1 sencn 
             // otherwise 2 sencond
// 

void solve() {
   string  s; cin >> s;

   int n = s.size(); 

   if(n == 1) {

    if(s == "a") cout << s << 'b' << "\n"; 
    else cout << s << 'a' << "\n"; 

   	return; 
   }  
   bool flag  = true; 
   for(int i=0; i<n; i++) {
 
     
   	 cout << s[i] << "";  
   	 if(flag && (s[i+1] == s[i])) {
   	 	flag = false; 
   	 	if(s[i] == 'a') cout << 'b' << ""; 
   	 	else 
   	 	cout << 'a' << "";
   	 }
   }

   if(flag) {
   	if(s[n-1] == 'a')
   	 cout << 'b' << ""; 
   	else
   	 cout << 'a' << ""; 
   }

   cout << "\n" << ""; 
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; 
    cin >> test_cases; 

    while(test_cases--) 
    solve();
    
    return 0;
}
