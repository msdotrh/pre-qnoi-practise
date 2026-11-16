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
vec<int> pre;
vec<int> ans;
int cyclep;

int dfs(int node) {
  visited[node] = 1;
  for (int v : graph[node]) {
    if (visited[v] && pre[node] != v) {
      pre[v] = node;
      cyclep = v;
      return -1;
    }
    if (!visited[v]) {
      pre[v] = node;
      if (dfs(v) == -1) {
        return -1;
      }
    }
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  pre.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bool found = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      if (dfs(i) == -1) {
        // thoat ngay lap tuc
        found = 1;
        break;
      }
    }
  }
  if (!found) {
    cout << "IMPOSSIBLE" << el;
    return 0;
  }
  // traverse
  vec<int> path;
  unordered_set<int> st;
  int curr = cyclep;
  while (st.find(curr) == st.end()) {
    path.push_back(curr);
    st.insert(curr);
    curr = pre[curr];
  }
  cout << path.size() + 1 << el;
  for (int x : path | ranges::views::reverse) {
    cout << x << " ";
  }
  cout << path.back();
  cout << el;
}
