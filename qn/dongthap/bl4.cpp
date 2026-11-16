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

void solve() {
  int n, q;
  cin >> n >> q;
  vec<int> d2(n + 5, 0);
  vec<int> d1(n + 5, 0);
  vec<int> a(n + 5, 0);
  while (q--) {
    int l, r;
    cin >> l >> r;
    d2[l]++;
    d2[r + 1] -= (r - l + 2);
    d2[r + 2] += (r - l + 1);
  }
  for (int i = 1; i <= n; i++) {
    d1[i] = d1[i - 1] + d2[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + d1[i];
  }
  cout << *r::max_element(a) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
