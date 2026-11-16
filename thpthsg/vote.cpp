// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <print>
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

int n, m;
vec<vec<int>> a;
vec<int> k;

int sum(int i) {
  int res = 0;
  for (int j = 0; j < n; j++) {
    res += a[j][i];
  }
  return res;
}

int res(int i) {
  // bat buoc bo giam khao thu i
  int mx = 0;
  for (int j = 0; j < n; j++) {
    if (j == i)
      continue;
    // bo giam khao thu j
    int curr = 0;
    for (int u = 0; u < m; u++) {
      int kk = k[u] - a[i][u] - a[j][u];
      if (kk >= n / 2) {
        curr++;
      }
    }
    mx = max(mx, curr);
  }
  return mx;
}

void solve() {
  cin >> n >> m;
  a.assign(n, vec<int>(m, 0));
  for (auto &x : a) {
    for (int &y : x) {
      cin >> y;
    }
  }
  k.assign(m, 0);
  for (int i = 0; i < m; i++) {
    k[i] = sum(i);
  }
  for (int i = 0; i < n; i++) {
    cout << res(i) << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
