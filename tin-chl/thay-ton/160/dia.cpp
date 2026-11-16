#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

vec<vec<int>> graph;

int n;
vec<int> bfs(int u) {
  vec<bool> visited(n + 1, 0);
  vec<int> cnt(n + 1, 0);
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : graph[x]) {
      if (!visited[v]) {
        q.push(v);
        visited[v] = 1;
        cnt[v] = cnt[x] + 1;
      }
    }
  }
  return cnt;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  graph.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    graph[i].push_back(p);
    graph[p].push_back(i);
  }
  // bfs
  auto cntv = bfs(1);
  int dinh1 = r::max_element(cntv | ranges::views::drop(1)) - r::begin(cntv);
  cntv = bfs(dinh1);
  int d = *r::max_element(cntv | ranges::views::drop(1));
  cout << d << el;
}
