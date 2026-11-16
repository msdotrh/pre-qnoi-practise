// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <print>
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

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vec<int> a(n + 2, 0);
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    a[l] += x;
    a[r + 1] -= x;
  }
  vec<int> res(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    res[i] = res[i - 1] + a[i];
  }
  sort(res.begin() + 1, res.begin() + n + 1);
  while (q--) {
    int k;
    cin >> k;
    auto it = lower_bound(res.begin() + 1, res.begin() + n + 1, k);
    int p = n - (it - res.begin()) + 1;
    cout << p << el;
  }
}

signed main() {
  io();
  open("WATER", "WATER");
  // cin >> t;
  while (t--) {
    solve();
  }
}
