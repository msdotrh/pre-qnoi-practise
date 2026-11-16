// #include <@msr.h>
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

int n;
vec<int> a;
vec<int> memo;

int dp(int i) {
  if (i < 0)
    return 0;
  if (i == 0)
    return a[i];
  int &mem = memo[i];
  if (mem != -1) {
    return mem;
  }
  if (i <= 8) {
    return mem = a[i] + dp(i - 1);
  }
  int tach = dp(i - 1) + a[i];
  int mn = MAX;
  int sum = 0;
  for (int j = i - 9; j <= i; j++) {
    mn = min(mn, a[j]);
    sum += a[j];
  }
  int gop = dp(i - 10) - mn + sum;
  return mem = min(tach, gop);
}

void solve() {
  cin >> n;
  a.resize(n);
  memo.assign(n + 1, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << dp(n - 1) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
