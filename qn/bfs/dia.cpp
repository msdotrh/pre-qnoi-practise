// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <ranges>
#include <string>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void open(string inp, string out) {
  string x = inp + ".inp";
  string y = out + ".out";
  freopen(x.c_str(), "r", stdin);
  freopen(y.c_str(), "w", stdout);
}

void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

int n;
vec<vec<int>> adj;

vec<int> bfs(int u) {
  vec<bool> visited(n + 1, 0);
  vec<int> dist(n + 1, 0);
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  dist[u] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (visited[v])
        continue;
      visited[v] = 1;
      dist[v] = dist[x] + 1;
      q.push(v);
    }
  }
  return dist;
}

void solve() {
  cin >> n;
  adj.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  // bfs
  vec init = bfs(1);
  int dinh1 = r::max_element(init) - r::begin(init);
  vec dk = bfs(dinh1);
  cout << *r::max_element(dk) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
