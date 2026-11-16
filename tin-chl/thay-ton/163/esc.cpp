// #include <@msr.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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

struct pos {
  double x, y;
};

vec<int> len;
vec<int> lead;
vec<pos> a;
int l, w, n;

void init() {
  len.assign(n + 2, 0);
  lead.assign(n + 2, 0);
  iota(lead.begin(), lead.end(), 0);
}

int find(int x) {
  if (x == lead[x]) {
    return x;
  }
  return lead[x] = find(lead[x]);
}

void unite(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (len[fx] < len[fy]) {
    swap(fx, fy);
  }
  len[fx] += fy;
  lead[fy] = fx;
}

double cal(pos x, pos y) { return hypot(abs(x.x - y.x), abs(x.y - y.y)); }

void solve() {
  cin >> l >> w >> n;
  a.assign(n + 2, {0.0, 0.0});
  init();
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double d = cal(a[i], a[j]);
      if (d <= 200.0) {
        unite(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    // tren: n + 1
    // duoi: 0
    if (a[i].y <= 100.0) {
      unite(i, 0);
    }
    if (w - a[i].y <= 100.0) {
      unite(i, n + 1);
    }
  }
  if (find(0) == find(n + 1)) {
    cout << "NO" << el;
  } else {
    cout << "YES" << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
