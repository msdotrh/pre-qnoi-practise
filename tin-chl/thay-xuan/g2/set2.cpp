// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
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

struct doan {
  int l, r;
};

void solve() {
  int n;
  cin >> n;
  vec<doan> a(n);
  for (auto &x : a) {
    cin >> x.l >> x.r;
  }
  r::sort(a, [](auto x, auto y) {
    if (x.r != y.r) {
      return x.r < y.r;
    }
    return x.l > y.l;
  });
  vec<doan> y;
  y.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    if (a[i].l > y.back().l) {
      y.push_back(a[i]);
    }
  }
  int cnt = 2;
  int lon_nhut = y[0].r;
  int lon_nhi = y[0].r - 1;
  for (int i = 1; i < y.size(); i++) {
    int r = y[i].r;
    int l = y[i].l;
    if (l <= lon_nhi) {
      // chua ca 2
      continue;
    } else if (l > lon_nhut) {
      lon_nhut = r;
      lon_nhi = r - 1;
      cnt += 2;
    } else {
      lon_nhi = lon_nhut;
      lon_nhut = r;
      cnt++;
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
