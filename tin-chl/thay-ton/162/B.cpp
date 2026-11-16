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
vec<int> cows;
vec<bool> visited;
vec<int> dadi;

void dfs(int u) {
  visited[u] = 1;
  dadi[u]++;
  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

void solve() {
  int k, n, m;
  cin >> k >> n >> m;
  adj.resize(n + 1);
  dadi.assign(n + 1, 0);
  while (k--) {
    int i;
    cin >> i;
    cows.push_back(i);
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for (int i : cows) {
    visited.assign(n + 1, 0);
    dfs(i);
  }
  int sum = 0;
  for (int x : dadi) {
    if (x == cows.size())
      sum++;
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
