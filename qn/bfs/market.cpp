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

vec<int> s;
vec<vec<int>> adj;
vec<int> dist;
vec<bool> visited;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  s.assign(k, 0);
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  dist.assign(n + 1, -1);
  for (int &x : s) {
    cin >> x;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(s[0]);
  visited[s[0]] = 1;
  dist[s[0]] = 0;
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
