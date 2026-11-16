// #include <@msr.h>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

struct canh {
  int v, w;
};

int n, q;
vec<vec<canh>> graph;

int djkk(int x, int y) {
  // x --->>> y
  vec<int> dist(n + 1, MAX);
  vec<bool> visited(n + 1, 0);

  priority_queue<pair<int, int>, vec<pair<int, int>>, greater<pair<int, int>>>
      pq;

  dist[x] = 0;
  pq.push({0, x});
  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (u == y)
      return dist[y];
    if (d > dist[u])
      continue;
    if (visited[u])
      continue;
    visited[u] = 1;
    for (auto i : graph[u]) {
      if (dist[u] + i.w < dist[i.v]) {
        dist[i.v] = dist[u] + i.w;
        pq.push({dist[i.v], i.v});
      }
    }
  }
  return dist[y];
}

void solve() {
  cin >> n >> q;
  graph.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << djkk(x, y) << el;
  }
}

signed main() {
  freopen("VILLAGE.INP", "r", stdin);
  freopen("VILLAGE.OUT", "w", stdout);
  // cin >> t;
  while (t--) {
    solve();
  }
}
