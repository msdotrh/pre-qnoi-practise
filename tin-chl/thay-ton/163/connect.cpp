// #include <@msr.h>
#include <cstdio>
#include <iostream>
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

vec<bool> visited;
vec<vec<int>> adj;

void dfs(int u) {
  visited[u] = 1;
  for (int v : adj[u]) {
    if (!visited[v])
      dfs(v);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  visited.assign(n + 1, 0);
  adj.resize(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
