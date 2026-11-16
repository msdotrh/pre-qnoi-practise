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

vec<int> len;
vec<vec<int>> adj;
vec<int> visited;
int n;

void dfs(int u) {
  visited[u] = 1;
  for (int v : adj[u]) {
    if (!visited[v]) {
      visited[v] = 1;
      dfs(v);
      len[u] += len[v];
    }
  }
}

void solve() {
  cin >> n;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  len.assign(n + 1, 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << len[i] << " ";
  }
  cout << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
