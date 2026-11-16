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

vec<vec<int>> adj;
vec<bool> visited;
vec<int> len;

int dfs(int u) {
  if (len[u] != -1)
    return len[u];
  visited[u] = 1;
  len[u] = 0;
  for (int v : adj[u]) {
    if (!visited[v]) {
      len[u] += dfs(v) + 1;
    }
  }
  return len[u];
}

void solve() {
  int n;
  cin >> n;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  len.assign(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    cout << dfs(i) << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
