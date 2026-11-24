// #include <@msr.h>
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

vec<vec<int>> adj;
vec<int> d;
vec<int> s;

int n, m, k;

void solve() {
  cin >> n >> m >> k;
  s.assign(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    cin >> s[i];
  }
  adj.resize(n + 1);
  d.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
  }
  queue<int> q;
  for (int k : s) {
    q.push(k);
    d[k] = 0;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int v : adj[x]) {
      if (d[v] == -1) {
        d[v] = d[x] + 1;
        q.push(v);
      }
    }
  }
  for (int x : d | ranges::views::drop(1)) {
    cout << x << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
