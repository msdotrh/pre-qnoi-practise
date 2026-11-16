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

vec<vec<bool>> grid;
int memo[55][55][4][2][2];
int n, k;

int dp(int x, int y, int k, bool tx, bool ty) {
  if (k < 0 || x < 0 || y < 0 || grid[x][y]) {
    return 0;
  }
  if (x == 0 && y == 0) {
    return 1;
  }
  int &mem = memo[x][y][k][tx][ty];
  if (mem != -1) {
    return mem;
  }
  if (tx) {
    int theo_x = dp(x - 1, y, k, 1, 0);
    int theo_y = dp(x, y - 1, k - 1, 0, 1);
    int res = theo_x + theo_y;
    return mem = res;
  } else {
    int theo_x = dp(x - 1, y, k - 1, 1, 0);
    int theo_y = dp(x, y - 1, k, 0, 1);
    int res = theo_x + theo_y;
    return mem = res;
  }
}

void solve() {
  cin >> n >> k;
  vec<string> a(n);
  for (string &s : a) {
    cin >> s;
  }
  grid.assign(n, vec<bool>(n, 0));
  memset(memo, -1, sizeof(memo));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c = a[i][j];
      if (c == 'H') {
        grid[i][j] = 1;
      }
    }
  }
  cout << dp(n - 1, n - 1, k, 0, 1) + dp(n - 1, n - 1, k, 1, 0) << el;
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
