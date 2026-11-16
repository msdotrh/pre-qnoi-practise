#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<vec<int>> graph;
vec<int> pre;
vec<bool> visited;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m, n;
  cin >> n >> m;
  graph.resize(n + 1);
  pre.assign(n + 1, 0);
  visited.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  // bfs
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    visited[x] = 1;
    for (int v : graph[x]) {
      if (!visited[v]) {
        q.push(v);
        if (pre[v] == 0) {
          pre[v] = x;
        }
        visited[v] = 1;
      }
    }
  }
  vec<int> path;
  int curr = n;
  while (curr != 0) {
    path.push_back(curr);
    curr = pre[curr];
  }
  if (!visited[n]) {
    cout << "IMPOSSIBLE" << el;
    return 0;
  }
  cout << path.size() << el;
  for (int x : ranges::views::reverse(path)) {
    cout << x << " ";
  }
  cout << el;
}
