// #include <@msr.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<bool> visited;
vec<vec<int>> graph;

void dfs(int u) {
  visited[u] = 1;
  for (int v : graph[u]) {
    if (!visited[v])
      dfs(v);
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
  // dfs
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      cnt++;
    }
  }
  cout << cnt << el;
}
