// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <print>
#include <queue>
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

int n, m, k;
vec<vec<int>> adj;
vec<int> s;
vec<bool> visited;
vec<int> dist;

void solve() {
  cin >> n >> m >> k;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  dist.assign(n + 1, -1);
  s.assign(k, 0);
  for (int &x : s) {
    cin >> x;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  for (int x : s) {
    q.push(x);
    visited[x] = 1;
    dist[x] = 0;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (!visited[v]) {
        dist[v] = dist[x] + 1;
        visited[v] = 1;
        q.push(v);
      }
    }
  }
  int d = r::max(dist | ranges::views::filter([](int x) { return x != -1; }));
  cout << d << el;
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
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
