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

int n, k;
vec<int> a;
vec<int> memo;

int dp(int i) {
  if (i >= n) {
    return 0;
  }

  int &mem = memo[i];
  if (mem != -1)
    return mem;

  int take = dp(i + k + 1) + a[i];
  int notake = dp(i + 1);
  return mem = max(take, notake);
}

void solve() {
  cin >> n >> k;
  a.assign(n, 0);
  memo.assign(n, -1);
  for (int &x : a) {
    cin >> x;
  }
  cout << dp(0) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
