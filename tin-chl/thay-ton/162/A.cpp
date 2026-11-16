// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
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

vec<int> lead;
vec<int> len;
int n, m, q;

void init() {
  lead.assign(n + 1, 0);
  iota(lead.begin(), lead.end(), 0);
  len.assign(n + 1, 1);
}

int find(int x) {
  if (lead[x] == x)
    return lead[x];
  return lead[x] = find(lead[x]);
}

void unite(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy)
    return;
  if (len[fx] < len[fy]) {
    swap(fx, fy);
  }
  lead[fy] = fx;
  len[fx] += len[fy];
}

void solve() {
  cin >> n >> m >> q;
  init();
  while (m--) {
    int u, v;
    cin >> u >> v;
    unite(u, v);
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (find(u) == find(v)) {
      cout << "YES" << el;
    } else {
      cout << "NO" << el;
    }
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
