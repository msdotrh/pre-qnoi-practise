// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<vec<int>> graph;
vec<bool> visited;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, s;
  cin >> n >> m >> s;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  while (m--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  stack<int> st;
  st.push(s);
  visited[s] = 1;
  vec<int> path;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    for (int v : graph[u]) {
      if (!visited[v]) {
        st.push(v);
        path.push_back(v);
        visited[v] = 1;
      }
    }
  }
  ranges::sort(path);
  if (path.empty()) {
    cout << -1 << el;
    return 0;
  }
  for (int x : path) {
    cout << x << " ";
  }
  cout << el;
}
