#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<bool> visited;
vec<vec<int>> graph;

void dfs(int u) {
  visited[u] = 1;
  for (int i = 0; i < graph[u].size(); i++) {
    if (!visited[graph[u][i]]) {
      dfs(graph[u][i]);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  visited.assign(n + 1, 0);
  graph.assign(n + 1, vec<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int cnt = 0;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cnt++;
      dfs(i);
      st.insert(i);
    }
  }
  cout << st.size() - 1 << el;
  int k = *st.begin();
  st.erase(st.begin());
  for (int i : st) {
    cout << k << " " << i << el;
  }
}
