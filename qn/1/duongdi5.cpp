// #include <@msr.h>
#include <cstdio>
#include <cstring>
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
const int M = 1e9 + 7;
vec<vec<int>> grid;
int memo[2004][2004];

int dp(int x, int y) {
  if (x == 0 && y == 0) {
    return 1;
  }
  if (x < 0 || y < 0) {
    return 0;
  }
  if (grid[x][y]) {
    return -1;
  }
  int res = 0;
  int &mem = memo[x][y];
  if (mem != -1) {
    return mem;
  }
  for (int i = x - 1; i >= 0; i--) {
    int tg = dp(i, y);
    if (tg == -1) {
      break;
    }
    res += tg;
    if (res >= M) {
      res -= M;
    }
  }
  for (int i = y - 1; i >= 0; i--) {
    int tg = dp(x, i);
    if (tg == -1) {
      break;
    }
    res += tg;
    if (res >= M) {
      res -= M;
    }
  }
  for (int i = 1; i <= min(x, y); i++) {
    int tg = dp(x - i, y - i);
    if (tg == -1) {
      break;
    }
    res += tg;
    if (res >= M) {
      res -= M;
    }
  }
  return mem = res;
}

void solve() {
  int h, w;
  cin >> h >> w;
  vec<string> a(h);
  grid.assign(h, vec<int>(w, 0));
  memset(memo, -1, sizeof(memo));
  for (string &x : a) {
    cin >> x;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c = a[i][j];
      if (c == '#') {
        grid[i][j] = 1;
      }
    }
  }
  cout << dp(h - 1, w - 1) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
