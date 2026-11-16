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
    return 1;
  }
  if (x < 0 || y < 0) {
    return 0;
  }
  int &mem = memo[x][y];
  if (mem != -1) {
    return mem;
  }
  return mem = dp(x - 1, y) + dp(x, y - 1);
}

void solve() {
  int m, n;
  cin >> m >> n;
  a.assign(m, vec<int>(n, 0));
  memo.assign(m, vec<int>(n, -1));
  cout << dp(m - 1, n - 1) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
