// #include <@msr.h>
#include <cstdio>
#include <cstdlib>
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

int n, k;
vec<int> a;

int memo[16][(1 << 15) + 6];

int dp(int i, int mask) {
  if (mask == (1 << n) - 1) {
    return 1;
  }

  int ans = 0;
  int &mem = memo[i][mask];
  if (mem != -1) {
    return mem;
  }
  for (int j = 0; j < n; j++) {
    if (abs(j - i) <= k && !(mask >> j & 1)) {
      ans += dp(j, mask | (1 << j));
    }
  }
  return mem = ans;
}

void solve() {
  cin >> n >> k;
  memset(memo, -1, sizeof(memo));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp(i, 1 << i);
  }
  cout << ans << el;
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
