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

vec<vec<int>> adj;
vec<bool> visited;
vec<int> dist;

void solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  dist.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  dist[s] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (!visited[v]) {
        visited[v] = 1;
        dist[v] = dist[x] + 1;
        q.push(v);
      }
    }
  }
  cout << dist[t] << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
