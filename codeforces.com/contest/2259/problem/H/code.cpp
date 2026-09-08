#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef MONU_LOCAL_JUDGE
#include "../cpp-dump/cpp-dump.hpp"
#define log(...) cpp_dump(__VA_ARGS__)
template <> inline void cpp_dump::write_log(std::string_view output) {
  std::cout << output << '\n';
}
#else
#define log(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
#endif

const int MOD = 1000000007;

long long modpow(long long a, long long e) {
  long long r = 1;
  while (e) {
    if (e & 1) r = r * a % MOD;
    a = a * a % MOD;
    e >>= 1;
  }
  return r;
}

long long countPath(long long n) {
  if (n == 0) return 1;
  if (n == 1) return 2;
  long long a = 2;
  long long b = 3;
  if (n == 2) return b;
  for (long long i = 3; i <= n; i++) {
    long long c = (a + b) % MOD;
    a = b;
    b = c;
  }
  return b;
}

long long solveCase(int n, std::vector<int> &b) {
  bool hasFixed = false;
  for (int x : b) if (x != -1) hasFixed = true;
  if (!hasFixed) {
    return (modpow(2, n) - 1 + MOD) % MOD;
  }
  std::vector<int> diff(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (b[i] > 0) {
      int k = b[i];
      int L = i - k, R = i + k;
      if (L < 0 && R >= n) return 0;
      int l = std::max(i - k + 1, 0);
      int r = std::min(i + k - 1, n - 1);
      if (l <= r) {
        diff[l]++;
        if (r + 1 < n) diff[r + 1]--;
        else diff[n]--;
      }
    } else if (b[i] > n) {
      return 0;
    }
  }
  std::vector<char> forcedZero(n, 0);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += diff[i];
    forcedZero[i] = (cur > 0);
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == 0 && forcedZero[i]) return 0;
  }
  std::vector<char> isMust1(n, 0), isMust0(n, 0);
  for (int i = 0; i < n; i++) {
    if (b[i] == 0) isMust1[i] = 1;
    if (forcedZero[i]) isMust0[i] = 1;
  }
  std::vector<char> forcedOne(n, 0);
  std::vector<std::pair<int,int>> tmpEdges;
  tmpEdges.reserve(n);
  for (int i = 0; i < n; i++) {
    if (b[i] <= 0) continue;
    int k = b[i];
    int L = i - k, R = i + k;
    bool vL = (L >= 0), vR = (R < n);
    auto stat = [&](int pos, bool valid) -> int {
      if (!valid) return 0;
      if (isMust1[pos]) return 1;
      if (isMust0[pos]) return 0;
      return 2;
    };
    int sL = stat(L, vL), sR = stat(R, vR);
    if (sL == 1 || sR == 1) continue;
    if (sL == 0 && sR == 0) return 0;
    if (sL == 0 && sR == 2) forcedOne[R] = 1;
    else if (sR == 0 && sL == 2) forcedOne[L] = 1;
    else if (sL == 2 && sR == 2) tmpEdges.emplace_back(L, R);
    else return 0;
  }
  std::vector<std::pair<int,int>> edges;
  edges.reserve(tmpEdges.size());
  for (auto &e : tmpEdges) {
    int u = e.first, v = e.second;
    if (forcedOne[u] || forcedOne[v]) continue;
    edges.emplace_back(u, v);
  }
  std::vector<char> inV(n, 0);
  for (int i = 0; i < n; i++) {
    if (b[i] == -1 && !isMust0[i] && !forcedOne[i]) inV[i] = 1;
  }
  for (auto &e : edges) {
    if (!inV[e.first] || !inV[e.second]) {
      int u = e.first, v = e.second;
      bool uOk = isMust1[u] || forcedOne[u];
      bool vOk = isMust1[v] || forcedOne[v];
      if (uOk || vOk) continue;
      return 0;
    }
  }
  std::vector<std::vector<int>> adj(n);
  for (auto &e : edges) {
    int u = e.first, v = e.second;
    if (!inV[u] || !inV[v]) continue;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::vector<char> vis(n, 0);
  std::vector<int> parent(n, -1);
  std::vector<long long> dp0(n, 0), dp1(n, 0);
  long long ans = 1;
  std::vector<int> stack, comp, order;
  for (int s = 0; s < n; s++) {
    if (!inV[s] || vis[s]) continue;
    comp.clear();
    stack.clear();
    stack.push_back(s);
    vis[s] = 1;
    size_t head = 0;
    std::vector<int> bfs;
    bfs.push_back(s);
    while (head < bfs.size()) {
      int u = bfs[head++];
      comp.push_back(u);
      for (int w : adj[u]) {
        if (!vis[w]) {
          vis[w] = 1;
          bfs.push_back(w);
        }
      }
    }
    int m = (int)comp.size();
    long long degSum = 0;
    int maxDeg = 0;
    for (int u : comp) {
      degSum += (int)adj[u].size();
      maxDeg = std::max(maxDeg, (int)adj[u].size());
    }
    long long eCnt = degSum / 2;
    if (m <= 20) {
      std::unordered_map<int,int> idx;
      idx.reserve(m*2);
      for (int i = 0; i < m; i++) idx[comp[i]] = i;
      std::vector<std::pair<int,int>> cEdges;
      for (int u : comp) {
        for (int w : adj[u]) {
          if (u < w) {
            cEdges.emplace_back(idx[u], idx[w]);
          }
        }
      }
      long long cnt = 0;
      int total = 1 << m;
      for (int mask = 0; mask < total; mask++) {
        bool ok = true;
        for (auto &ce : cEdges) {
          if (!(mask & (1 << ce.first)) && !(mask & (1 << ce.second))) { ok = false; break; }
        }
        if (ok) cnt++;
      }
      ans = ans * (cnt % MOD) % MOD;
      continue;
    }
    if (eCnt == (long long)m - 1) {
      int root = comp[0];
      order.clear();
      order.reserve(m);
      std::vector<int> st;
      st.push_back(root);
      parent[root] = root;
      while (!st.empty()) {
        int u = st.back(); st.pop_back();
        order.push_back(u);
        for (int w : adj[u]) {
          if (parent[w] == -1) {
            parent[w] = u;
            st.push_back(w);
          }
        }
      }
      for (int i = m - 1; i >= 0; i--) {
        int u = order[i];
        long long a0 = 1, a1 = 1;
        for (int w : adj[u]) {
          if (w == parent[u] && u != root) continue;
          if (parent[w] != u) continue;
          a0 = a0 * dp1[w] % MOD;
          a1 = a1 * ((dp0[w] + dp1[w]) % MOD) % MOD;
        }
        dp0[u] = a0;
        dp1[u] = a1;
      }
      long long tot = (dp0[root] + dp1[root]) % MOD;
      ans = ans * tot % MOD;
      for (int u : comp) parent[u] = -1;
    } else if (eCnt == (long long)m && maxDeg == 2) {
      long long tot = (countPath(m - 1) + countPath(m - 3 < 0 ? 0 : m - 3)) % MOD;
      ans = ans * tot % MOD;
      for (int u : comp) parent[u] = -1;
    } else {
      return 0;
    }
  }
  return ans % MOD;
}

class Solution {
public:
  void solve() {
    int n;
    if (!(std::cin >> n)) return;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) std::cin >> b[i];
    std::cout << solveCase(n, b) << '\n';
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  Solution sol;
  while (t--) {
    sol.solve();
  }

  return 0;
}
