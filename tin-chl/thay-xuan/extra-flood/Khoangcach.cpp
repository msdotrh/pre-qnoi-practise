// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <queue>
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

void solve() {
  int n;
  cin >> n;
  vec<vec<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vec<bool> visited(n + 1, 0);
  vec<int> dist(n + 1, -1);
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  visited[1] = 1;
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
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
