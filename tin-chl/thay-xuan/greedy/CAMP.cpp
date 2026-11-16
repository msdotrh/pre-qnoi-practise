// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
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
int MAX = 1e14;
int MIN = -MAX;

vec<pair<int, int>> a;
vec<pair<int, int>> b;
int memo[1005][1005][2];
int m, n;

int cal(pair<int, int> x, pair<int, int> y) {
  int a = abs(x.first - y.first);
  int b = abs(x.second - y.second);
  return a * a + b * b;
}

int dp(int i, int j, bool tp) {
  if (i == m - 1 && j == n - 1) {
    if (!tp)
      return 0;
    else
      return MAX;
  }
  int mn = MAX;
  int &mem = memo[i][j + 1][tp];
  if (mem != -1)
    return mem;
  pair<int, int> cur;
  if (!tp) {
    cur = a[i];
  } else {
    cur = b[j];
  }
  if (i + 1 < m) {
    // di ha noi
    int tg = dp(i + 1, j, 0);
    if (tg < MAX) {
      mn = min(mn, tg + cal(cur, a[i + 1]));
    }
  }
  if (j + 1 < n) {
    // di sg
    int tg = dp(i, j + 1, 1);
    if (tg < MAX) {
      mn = min(mn, tg + cal(cur, b[j + 1]));
    }
  }
  return mem = mn;
}

void solve() {
  cin >> m >> n;
  int m2 = m, n2 = n;
  memset(memo, -1, sizeof(memo));
  while (m2--) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
  while (n2--) {
    int x, y;
    cin >> x >> y;
    b.push_back({x, y});
  }
  cout << dp(0, -1, 0) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}

