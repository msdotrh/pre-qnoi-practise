// #include <@msr.h>
#include <cstdio>
#include <cstring>
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

struct Node {
  int u, w;
};

vec<vec<Node>> adj;
vec<int> visited;
int dist[1005][1005];

void dfs(int stem, int u, int w) {
  visited[u] = 1;
  dist[stem][u] = w;
  for (Node v : adj[u]) {
    if (!visited[v.u]) {
      dfs(stem, v.u, w + v.w);
    }
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  for (int i = 1; i < n; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    adj[a].push_back({b, l});
    adj[b].push_back({a, l});
  }
  for (int i = 1; i <= n; i++) {
    visited.assign(n + 1, 0);
    dfs(i, i, 0);
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << dist[u][v] << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
