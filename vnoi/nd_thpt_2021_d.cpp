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

int n;
vec<int> tv, pv;
vec<int> memo;

int dp(int i) {
  if (i > n)
    return MAX;
  if (i == n)
    return 0;
  int &mem = memo[i];
  if (mem != -1) {
    return mem;
  }
  int lamrieng = dp(i + 1) + tv[i];
  int lamchung = MAX;
  if (i + 2 <= n) {
    lamchung = dp(i + 2) + pv[i];
  }
  return mem = min(lamchung, lamrieng);
}

void solve() {
  cin >> n;
  tv.assign(n, 0);
  pv.assign(n - 1, 0);
  memo.assign(n + 1, -1);
  for (int &x : tv) {
    cin >> x;
  }
  for (int &x : pv) {
    cin >> x;
  }
  cout << dp(0) << el;
}

signed main() {
  io();
  open("WORK", "WORK");
  // cin >> t;
  while (t--) {
    solve();
  }
}
