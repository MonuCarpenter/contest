#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> p;
    for (int i = 0; i < n; i++)
      if (a[i] == 1) p.push_back(i);
    if (p.empty()) {
      int f = -1, l = -1;
      for (int i = 0; i < n; i++)
        if (a[i] == -1) {
          if (f == -1) f = i;
          l = i;
        }
      if (f != -1 && l != f) {
        a[f] = a[l] = 1;
        for (int &x : a)
          if (x == -1) x = 0;
      } else {
        for (int &x : a)
          if (x == -1) x = 1;
      }
    } else {
      int bl = -1, br = -1, bn = -1;
      for (size_t k = 0; k + 1 < p.size(); k++) {
        int L = p[k], R = p[k + 1];
        if (R - L + 1 > bn) bn = R - L + 1, bl = L, br = R;
      }
      int f = -1;
      for (int i = 0; i < p[0]; i++)
        if (a[i] == -1 && f == -1) f = i;
      if (f != -1 && p[0] - f + 1 > bn) bn = p[0] - f + 1, bl = f, br = p[0];
      int l = -1;
      for (int i = p.back() + 1; i < n; i++)
        if (a[i] == -1) l = i;
      if (l != -1 && l - p.back() + 1 > bn) bn = l - p.back() + 1, bl = p.back(), br = l;
      if (bn != -1) {
        a[bl] = a[br] = 1;
        for (int i = bl + 1; i < br; i++)
          if (a[i] == -1) a[i] = 0;
        for (int &x : a)
          if (x == -1) x = 0;
      }
    }
    for (int i = 0; i < n; i++) cout << a[i] << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}
