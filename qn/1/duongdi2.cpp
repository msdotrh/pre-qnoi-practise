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
const int M = 1e9 + 7;

vec<vec<int>> gg;
vec<vec<int>> memo;
int dp(int x, int y) {
  if (x < 0 || y < 0) {
    return 0;
  }
  if (gg[x][y]) {
    return 0;
  }
  if (x == 0 && y == 0) {
    return 1;
  }
  int &mem = memo[x][y];
  if (mem != -1) {
    return mem;
  }
  int res = dp(x - 1, y) + dp(x, y - 1);
  return mem = res % M;
}

void solve() {
  int h, w;
  cin >> h >> w;
  vec<string> g(h);
  for (string &s : g) {
    cin >> s;
  }
  gg.assign(h, vec<int>(w));
  memo.assign(h, vec<int>(w, -1));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] == '.') {
        gg[i][j] = 0;
      } else if (g[i][j] == '#') {
        gg[i][j] = 1;
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
