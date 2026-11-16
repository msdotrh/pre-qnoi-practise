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
vec<vec<int>> a;
vec<vec<int>> memo;

int dp(int x, int y) {
  if (x == 0 && y == 0) {
    return a[x][y];
  }
  int mx = MAX;
  int &mem = memo[x][y];
  if (mem != -1) {
    return mem;
  }
  if (y == 0) {
    mx = dp(x - 1, y);
  } else if (x == 0) {
    mx = dp(x, y - 1);
  } else {
    mx = min(dp(x, y - 1), dp(x - 1, y));
  }
  int res = mx + a[x][y];
  return mem = res;
}

int n, m;

void solve() {
  cin >> n >> m;
  a.assign(n, vec<int>(m, 0));
  memo.assign(n, vec<int>(m, -1));
  for (auto &x : a) {
    for (int &y : x) {
      cin >> y;
    }
  }
  cout << dp(n - 1, m - 1) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
