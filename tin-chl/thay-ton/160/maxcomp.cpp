#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

vec<vec<int>> graph;
vec<bool> visited;
vec<int> a;

int dfs(int u) {
  int sum = a[u];
  visited[u] = 1;
  for (int v : graph[u]) {
    if (!visited[v]) {
      sum += dfs(v);
    }
  }
  return sum;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  a.assign(n + 1, 0);
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int mx = -1e18;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      int tg = dfs(i);
      mx = max(mx, tg);
    }
  }
  cout << mx << el;
}
