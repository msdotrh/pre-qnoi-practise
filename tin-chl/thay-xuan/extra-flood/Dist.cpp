// #include <@msr.h>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T>;
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
vec<int> dist;

int n, m, x, y;

void solve() {
  cin >> n >> m >> x >> y;
  adj.resize(n + 1);
  dist.assign(n + 1, -1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(x);
  dist[x] = 0;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int v : adj[k]) {
      if (dist[v] != -1) continue;
      dist[v] = dist[k] + 1;
      q.push(v);
    }
  }
  cout << dist[y] << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
