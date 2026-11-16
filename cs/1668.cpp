// #include <@msr.h>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

enum group { G1, G2, NONE };

void bfs(int u, auto &graph, auto &state) {
  queue<int> q;
  q.push(u);
  state[u] = G1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : graph[x]) {
      if (state[v] != NONE) {
        // check if state[x] != state[v] and same parent
        // if yes: ok
        // if not: impossible
        if (state[x] == state[v]) {
          cout << "IMPOSSIBLE" << el;
          exit(EXIT_SUCCESS);
        }
      } else {
        if (state[x] == G1) {
          state[v] = G2;
        } else {
          state[v] = G1;
        }
        q.push(v);
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m, n;
  cin >> n >> m;
  vec<group> state(n + 1, NONE);
  vec<vec<int>> graph(n + 1, vec<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (state[i] == NONE)
      bfs(i, graph, state);
  }
  for (int x : state | ranges::views::drop(1)) {
    cout << x + 1 << " ";
  }
  cout << el;
}
