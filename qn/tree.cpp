// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <print>
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

vec<vec<int>> adj;
vec<int> a;
vec<int> visited;
vec<vec<int>> lead;
int n, qq;

void solve() {
  cin >> n >> qq;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  lead.resize(n + 1);
  a.assign(n, 0);
  for (int& x : a) {
    cin >> x;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<int> q;
  visited.assign(n + 1, 1);
  q.push(1);
  visited[1] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (visited[v]) continue;
      lead[v] = lead[x];
      lead[v].push_back(x);
      visited[v] = 1;
      q.push(v);
    }
  }
  println("{}", lead);
  for (int i = 0; i < qq; i++) {
    int x, y;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
