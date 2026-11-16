#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
template <typename T> using vec = vector<T>;
template <typename T, typename U> using p = pair<T, U>;
#define printv(v)                                                              \
  for (const auto &e : v)                                                      \
    cout << e << " ";                                                          \
  cout << "\n"
#define readv(v)                                                               \
  for (auto &e : v)                                                            \
  cin >> e
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using ld = long double;
using ull = unsigned long long;

char el = '\n';

void open(string s) {
  freopen((s + ".INP").c_str(), "r", stdin);
  freopen((s + ".OUT").c_str(), "w", stdout);
}

int m, n;
vec<vec<int>> graph;
vec<bool> visited;

pair<vec<int>, int> bfs(int u) {
  vec<int> dist(n + 1, 0);
  int cnt = 0;
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    cnt++;
    for (int v : graph[x]) {
      if (!visited[v]) {
        visited[v] = 1;
        dist[v] = dist[x] + 1;
        q.push(v);
      }
    }
  }
  return {dist, cnt};
}

pair<int, int> solve(int u) {
  pair<vec<int>, int> y = bfs(u);
  int mx = max_element(y.first.begin() + 1, y.first.end()) - y.first.begin();
  visited.assign(n + 1, 0);
  pair<vec<int>, int> x = bfs(mx);
  int mxx = *max_element(x.first.begin() + 1, x.first.end());
  return {x.second, mxx};
}

int main() {
  open("TREE");
  cin >> n >> m;
  graph.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  visited.assign(n + 1, 0);
  vec<pair<int, int>> ps;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      ps.push_back(solve(i));
    }
  }
  sort(ps.begin(), ps.end(), [](pair<int, int> &x, pair<int, int> &y) {
    if (x.first == y.first) {
      return x.second < y.second;
    }
    return x.first < y.first;
  });
  cout << ps.size() << el;
  for (auto &i : ps) {
    cout << i.first << " " << i.second << el;
  }
}
