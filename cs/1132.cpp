// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
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

int n;
vec<vec<int>> adj;

vec<int> bfs(int u) {
  vec<int> dist(n + 1, -1);
  queue<int> q;
  q.push(u);
  dist[u] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (dist[v] != -1)
        continue;
      dist[v] = dist[x] + 1;
      q.push(v);
    }
  }
  return dist;
}

void solve() {
  cin >> n;
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  auto init = bfs(1);
  int dinhA = r::max_element(init) - r::begin(init);
  auto distA = bfs(dinhA);
  int dinhB = r::max_element(distA) - r::begin(distA);
  auto distB = bfs(dinhB);
  for (int i = 1; i <= n; i++) {
    int mx = max(distA[i], distB[i]);
    cout << mx << " ";
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
