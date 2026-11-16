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

int n;
vec<int> p, a, b;

void update(int i, int x) {
  for (int j = 0; j <= i; j++) {
    a[j] += x;
    int x = a[j], y = b[j];
    p[j] = (y - (x % y)) % y;
  }
}

void solve() {
  cin >> n;
  p.assign(n, 0);
  a = p, b = p;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = x;
    b[i] = y;
    p[i] = (y - (x % y)) % y;
  }
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = p[i];
    update(i, x);
    int ok = 1;
    for (int j = 0; j < n; j++) {
      if (a[j] != 0) {
        ok = 0;
      }
    }
    if (ok) {
      break;
    } else {
      cnt += x;
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
