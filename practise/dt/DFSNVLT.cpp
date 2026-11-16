// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<vec<int>> graph;
vec<bool> visited;
vec<int> lt;

void dfs(int u) {
  visited[u] = 1;
  lt.push_back(u);
  for (int v : graph[u]) {
    if (visited[v])
      continue;
    dfs(v);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  visited.assign(n + 1, 0);
  graph.resize(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int mx = 0;
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    dfs(i);
    if (mx < lt.size()) {
      mx = lt.size();
      k = i;
    }
    lt.clear();
  }
  cout << mx << el;
  lt.clear();
  visited.assign(n + 1, 0);
  dfs(k);
  ranges::sort(lt);
  for (int x : lt) {
    cout << x << " ";
  }
  cout << el;
}
