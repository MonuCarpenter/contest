/*
 * Author: Monu Carpenter
 * Time: 2024-07-20 01:11:33
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int n;
  cin >> n;

  while (n--)
  {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    int k = 5;
    while (k--)
    {
      sort(v.begin(), v.end());
      v[0] += 1;
    }

    int result = v[0] * v[1] * v[2];

    cout << result << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
