#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<vec<int>> graph;
vec<bool> visited;

void dfs(int u) {
  visited[u] = 1;
  for (int v : graph[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt << el;
}
