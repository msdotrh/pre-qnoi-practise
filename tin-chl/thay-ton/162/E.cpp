// #include <@msr.h>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
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

vec<vec<int>> adj;
vec<bool> visited;
map<int, set<int>> mp;

void dfs(int u, int id) {
  visited[u] = 1;
  mp[id].insert(u);
  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(v, id);
    }
  }
}

void solve() {
  int m, n;
  cin >> n >> m;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int id = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i, id);
      id++;
    }
  }
  cout << mp.size() << el;
  for (auto &i : mp) {
    for (int k : i.second) {
      cout << k << " ";
    }
    cout << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
