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

int n;
vec<vec<int>> a;
int memo[22][(1 << 21) + 5];

int dp(int i, int mask) {
  // xet nam thu i
  // xet mask la nu da dc chon

  if (i == n) {
    return (mask == (1 << n) - 1) ? 1 : 0;
  }

  int &mem = memo[i][mask];
  if (mem != -1) {
    return mem;
  }

  int ans = 0;
  for (int j = 0; j < n; j++) {
    if (!(mask >> j & 1) && a[i][j]) {
      // chua dc chon, thoa man
      ans += dp(i + 1, mask | (1 << j));
      if (ans >= M) {
        ans -= M;
      }
    }
  }
  return mem = ans;
}

void solve() {
  cin >> n;
  a.assign(n, vec<int>(n));
  memset(memo, -1, sizeof(memo));
  for (auto &x : a) {
    for (int &y : x) {
      cin >> y;
    }
  }
  cout << dp(0, 0) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
