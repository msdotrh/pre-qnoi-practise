// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <print>
#include <string>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void open(string inp, string out) {
  string x = inp + ".inp";
  string y = out + ".out";
  freopen(x.c_str(), "r", stdin);
  freopen(y.c_str(), "w", stdout);
}

void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

vec<int> visited;
vec<vec<int>> adj;
vec<int> lead;

void dfs(int u) {
  visited[u] = 1;
  for (int v : adj[u]) {
    if (visited[v])
      continue;
    lead[v] = u;
    dfs(v);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  visited.assign(n + 1, 0);
  adj.resize(n + 1);
  lead.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  r::iota(lead, 0);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  vec<int> d(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (lead[i] != i) {
      d[lead[i]]++;
    }
  }
  /*for (int i = 1; i <= n; i++) {
    cout << d[i] << " ";
  }*/
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (d[lead[i]] < d[i]) {
      // cout << "dinh " << i << el;
      // cout << lead[i] << el;
      cnt++;
    }
  }
  cout << cnt << el;
}

signed main() {
  // cin >> t;
  while (t--) {
    solve();
  }
}
