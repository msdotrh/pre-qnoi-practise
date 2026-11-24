// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T>;
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
vec<int> p;
vec<vec<int>> memo;

int dp(int x, int sum) {
  if (sum >= k) {
    return 0;
  }
  if (x >= n) {
    return MIN;
  }
  int& mem = memo[x][sum];
  if (mem != -1) {
    return mem;
  }
  int res = MIN;
  int take = dp(x + 1, sum + a[x]) + 1;
  int skip = dp(x + 1, sum);
  res = max(take, skip);
  return mem = res;
}

void trace(int x, int sum) {
  if (sum >= k) {
    return;
  }
  if (x >= n) {
    return;
  }
  int take = dp(x + 1, sum + a[x]) + 1;
  int skip = dp(x + 1, sum);
  if (dp(x, sum) == take) {
    cout << a[x] << " ";
    trace(x + 1, sum + a[x]);
  } else {
    trace(x + 1, sum);
  }
}

void solve() {
  cin >> n >> k;
  a.assign(n, 0);
  memo.assign(n + 1, vec<int>(k + 1, -1));
  for (int& x : a) cin >> x;
  cout << dp(0, 0) << el;
  trace(0, 0);
  cout << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
