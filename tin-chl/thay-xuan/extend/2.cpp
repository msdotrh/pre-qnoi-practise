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

int n, k;
vec<int> a;

vec<int> check(int kc) {
  vec<int> visited(n + 1, 0);
  vec<int> res;
  if (a.back() - a.front() <= kc) {
    res.push_back(0);
  }
  int ccx = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[ccx] > kc) {
      res.push_back(i - 1);
      ccx = i;
    }
  }
  if (a.front() - a[res.back()] > kc) {
    res.push_back(n - 1);
  }
  return res;
}

void solve() {
  cin >> n >> k;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  int l = 0, r = a.back();
  vec<int> ans;
  while (l <= r) {
    int m = (l + r) / 2;
    vec<int> tg = check(m);
    if (tg.size() <= k) {
      // tmdk
      ans = tg;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  for (int x : ans) {
    cout << x + 1 << el;
  }
}

signed main() {
  // cin >> t;
  while (t--) {
    solve();
  }
}
