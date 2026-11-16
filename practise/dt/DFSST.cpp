// #include <@msr.h>
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
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  while (m--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  stack<int> st;
  vec<int> prev(n + 1, 0);
  st.push(s);
  visited[s] = 1;
  while (!st.empty()) {
    int x = st.top();
    st.pop();
    for (int v : graph[x]) {
      if (!visited[v]) {
        st.push(v);
        visited[v] = 1;
        prev[v] = x;
      }
    }
  }
  if (!visited[t]) {
    cout << -1 << el;
    return 0;
  }
  int curr = t;
  while (curr != 0) {
    cout << curr << " ";
    curr = prev[curr];
  }
  cout << el;
}
