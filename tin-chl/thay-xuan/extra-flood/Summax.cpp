// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ranges>
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

int n;
vec<int> a;
vec<vec<int>> adj;
vec<bool> visited;

void unite(int x, int y) {
  adj[x].push_back(y);
  adj[y].push_back(x);
}

int dfs(int u) {
  visited[u] = 1;
  int cur = a[u];
  int mx = 0;
  for (int v : adj[u]) {
    if (!visited[v]) {
      visited[v] = 1;
      mx = max(mx, dfs(v));
    }
  }
  int res = cur + mx;
  return res;
}

void solve() {
  cin >> n;
  a.assign(n + 1, 0);
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  for (int &x : a | ranges::views::drop(1)) {
    cin >> x;
  }
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    if (k != 0) {
      unite(i, k);
    }
  }
  cout << dfs(1) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
