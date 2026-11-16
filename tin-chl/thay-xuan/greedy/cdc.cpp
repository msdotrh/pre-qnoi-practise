// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
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
vec<int> a;
vec<int> memo;

int dp(int i) {
  if (i >= n)
    return 0;

  int &mem = memo[i];
  if (mem != -1) {
    return mem;
  }

  int take1 = dp(i + 2) + a[i];
  int take2 = dp(i + 4) + a[i] + a[i + 1];
  int take3 = dp(i + 6) + a[i] + a[i + 1] + a[i + 2];
  int res = max({take1, take2, take3});
  return mem = res;
}

void solve() {
  cin >> n;
  a.assign(n, 0);
  memo.assign(n + 100, -1);
  for (int &x : a) {
    cin >> x;
  }
  a.resize(n + 100, 0);
  cout << dp(0) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
