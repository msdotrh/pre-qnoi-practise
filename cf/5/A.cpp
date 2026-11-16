// #include <@msr.h>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<vec<int>> graph;
vec<bool> visited;
vec<int> pre;

void dfs(int x) {
  visited[x] = 1;
  for (int v : graph[x]) {
    if (!visited[v]) {
      dfs(v);
      pre[v] = x;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  pre.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    int k;
    cin >> k;
    graph[k].push_back(i);
    graph[i].push_back(k);
  }
  dfs(1);
  vec<int> path;
  int curr = n;
  while (curr != 0) {
    path.push_back(curr);
    curr = pre[curr];
  }
  for (int x : ranges::views::reverse(path)) {
    cout << x << " ";
  }
  cout << el;
}
