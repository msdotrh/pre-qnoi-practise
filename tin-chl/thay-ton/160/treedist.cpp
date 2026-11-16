#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

vec<vec<int>> graph;
vec<bool> visited;
vec<int> cnt;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  graph.resize(n + 1);
  visited.assign(n + 1, 0);
  cnt.assign(n + 1, 0);
  n--;
  while (n--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // bfs
  queue<int> q;
  q.push(1);
  visited[1] = 1;
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
  for (int x : cnt | ranges::views::drop(1)) {
    cout << x << " ";
  }
  cout << el;
}
