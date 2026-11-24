// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T>;
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

int bfs(int u) {
  vec<int> d(n + 1, -1);
  queue<int> q;
  q.push(u);
  d[u] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (d[v] != -1) continue;
      d[v] = d[x] + 1;
      q.push(v);
    }
  }
  int sum = accumulate(d.begin() + 1, d.end(), 0);
  return sum;
}

void solve() {
  cin >> n;
  int m = n - 1;
  adj.resize(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    cout << bfs(i) << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
