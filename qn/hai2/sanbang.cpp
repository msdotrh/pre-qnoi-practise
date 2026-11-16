// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
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

int n, k;

void solve() {
  cin >> n >> k;
  vec<int> h(n);
  for (int &x : h) {
    cin >> x;
  }
  r::sort(h);
  int m1 = n / 2;
  int m2 = n / 2;
  if (n % 2 == 0)
    m2--;
  vec a = h;
  vec b = h;
  r::sort(a, [&](int x, int y) { return abs(x - h[m1]) < abs(y - h[m1]); });
  r::sort(b, [&](int x, int y) { return abs(x - h[m2]) < abs(y - h[m2]); });
  int res1 = 0;
  int res2 = 0;
  int k1 = k;
  int k2 = k;
  /*
  println("{}\n{}\n{}", h, a, b);
  println("{} {}", m1, m2);
  */
  for (int i = 0; i < n; i++) {
    if (k1 - abs(h[m1] - a[i]) < 0)
      break;
    k1 -= abs(h[m1] - a[i]);
    a[i] = h[m1];
  }
  for (int i = 0; i < n; i++) {
    if (k2 - abs(h[m2] - b[i]) < 0)
      break;
    k2 -= abs(h[m2] - b[i]);
    b[i] = h[m2];
  }
  map<int, int> mp1;
  for (int i = 0; i < n; i++) {
    mp1[a[i]]++;
  }
  map<int, int> mp2;
  for (int i = 0; i < n; i++) {
    mp2[b[i]]++;
  }
  int mx1 = 0;
  for (auto i : mp1) {
    mx1 = max(mx1, i.second);
  }
  int mx2 = 0;
  for (auto i : mp2) {
    mx2 = max(mx2, i.second);
  }
  cout << max(mx1, mx2) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
