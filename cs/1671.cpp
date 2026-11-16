// #include <@msr.h>
#include <bits/stdc++.h>
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

int d() {
  // tu 1 den b;
  pq.push({1, 0});
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
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  f.assign(n + 1, INT64_MAX);
  f[1] = 0;
  for (int i = 0; i < m; i++) {
    int a;
    node b;
    cin >> a >> b.n >> b.w;
    graph[a].push_back(b);
  }
  d();
  for (int x : f | ranges::views::drop(1)) {
    cout << x << " ";
  }
  cout << el;
}
