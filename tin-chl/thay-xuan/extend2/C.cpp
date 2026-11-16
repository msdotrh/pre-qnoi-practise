// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <queue>
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

void solve() {
  int m, n, k;
  cin >> n >> m >> k;
  vec<int> s(k);
  for (int i = 0; i < k; i++) {
    cin >> s[i];
  }
  vec<vec<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
  }
  queue<int> q;
  vec<int> dist(n + 1, -1);
  for (int i = 0; i < k; i++) {
    int u = s[i];
    dist[u] = 0;
    q.push(u);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (dist[v] == -1) {
        dist[v] = dist[x] + 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
