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

vec<vec<int>> k;
int n, m;

void flip(int x, int y) {
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      k[i][j] ^= 1;
    }
  }
}

void solve() {
  cin >> n >> m;
  vec<string> a(n);
  for (string &s : a) {
    cin >> s;
  }
  int cnt = 0;
  k.assign(n, vec<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      k[i][j] = a[i][j] - '0';
    }
  }
  /*
  for (auto i : k) {
    println("{}", i);
  }
  */
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (!k[i][j]) {
        flip(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
