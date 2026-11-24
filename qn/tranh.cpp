// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <numeric>
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

bool check(int x) {
  int sum = 0;
  int cnt = 1;
  for (int y : a) {
    if (sum + y <= x) {
      sum += y;
    } else {
      cnt++;
      sum = y;
    }
  }
  return cnt <= k;
}

void solve() {
  cin >> n >> k;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  int l = r::max(a), r = accumulate(a.begin(), a.end(), 0);
  int ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
