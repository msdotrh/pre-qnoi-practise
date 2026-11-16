// #include <@msr.h>
#include <algorithm>
#include <bitset>
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

void sub1() {
  int cnt = 0;
  int lim = n * m;
  for (int mask = 0; mask < (1 << lim); mask++) {
    vec<vec<int>> tt(n, vec<int>(m, 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mask >> (i * m + j) & 1) {
          tt[i][j] = -1;
        }
      }
    }
    int ok1 = 1, ok2 = 1;
    for (auto &y : tt) {
      int p = 1;
      for (int x : y) {
        p *= x;
      }
      if (p == -1) {
        ok1 = 0;
        break;
      }
    }
    for (int i = 0; i < m; i++) {
      int p = 1;
      for (int j = 0; j < n; j++) {
        p *= tt[j][i];
      }
      if (p == -1) {
        ok2 = 0;
        break;
      }
    }
    if (ok1 && ok2) {
      /*
      println("ok tai :");
      for (auto &x : tt) {
        println("{}", x);
      }
      println("{}", bitset<2 * 3>(mask).to_string());
      */
      cnt++;
    }
  }
  cout << cnt << el;
}

void solve() {
  cin >> n >> m;
  sub1();
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
