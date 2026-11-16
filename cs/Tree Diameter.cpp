// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<vec<int>> tree;
int n;

vec<int> bfs(int u) {
  vec<int> dist(n + 1, 0);
  vec<int> visited(n + 1, 0);
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    visited[x] = 1;
    for (int v : tree[x]) {
      if (!visited[v]) {
        q.push(v);
        dist[v] = dist[x] + 1;
      }
    }
  }
  return dist;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  tree.resize(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  vec<int> first = bfs(1);
  int first_point = ranges::max_element(first) - first.begin();
  vec<int> second = bfs(first_point);
  cout << *ranges::max_element(second);
  cout << el;
}
