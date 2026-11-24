// #include <@msr.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

struct node {
  int n, w;
};

vec<int> f, visited;
vec<vec<node>> graph;
priority_queue<node, vec<node>,
               decltype([](node x, node y) { return x.w > y.w; })>
    pq;

int n, m, s, t;

int d() {
  // tu 1 den b;
  pq.push({s, 0});
  while (!pq.empty()) {
    node x = pq.top();
    pq.pop();
    if (visited[x.n]) {
      continue;
    }
    visited[x.n] = 1;
    for (node v : graph[x.n]) {
      // calculate cost
      int c = v.w + x.w;
      if (c < f[v.n]) {
        f[v.n] = c;
        pq.push({v.n, c});
      }
    }
  }
  return -1;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> s >> t;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  f.assign(n + 1, INT64_MAX);
  f[s] = 0;
  for (int i = 0; i < m; i++) {
    node a;
    node b;
    cin >> a.n >> b.n >> b.w;
    a.w = b.w;
    graph[a.n].push_back(b);
    graph[b.n].push_back(a);
  }
  d();
  cout << f[t] << el;
}
