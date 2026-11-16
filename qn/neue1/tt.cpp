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
vec<int> a;
vec<int> visited;
vec<int> sz;

int dfs(int u) {
  int sum = a[u];
  for (int v : adj[u]) {
    if (!visited[v]) {
      visited[v] = 1;
      sum += dfs(v);
    }
  }
  return sum;
}

void solve() {
  int n;
  cin >> n;
  a.resize(n + 1);
  visited.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    visited.assign(n + 1, 0);
    visited[i] = 1;
    sum += dfs(i);
  }
  cout << sum << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
