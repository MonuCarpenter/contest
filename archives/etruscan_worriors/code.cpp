#include <bits/stdc++.h>
using namespace std;

int solve() {
  long long n;
  cin >> n;

  long long ans = (sqrt(1 + 8.0 * n) - 1) / 2;
  cout << ans << '\n';
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
