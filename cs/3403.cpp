// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <format>
#include <iostream>
#include <ranges>
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

int n, m;
vec<int> a, b, res;
int memo[1005][1005];

int dp(int n, int m) {
  if (n == 0 || m == 0) {
    return 0;
  }
  int &mem = memo[n][m];
  if (mem != -1) {
    return mem;
  }
  if (a[n - 1] == b[m - 1]) {
    return mem = 1 + dp(n - 1, m - 1);
  } else {
    return mem = max(dp(n - 1, m), dp(n, m - 1));
  }
}

void solve() {
  cin >> n >> m;
  a.assign(n, 0);
  b.assign(m, 0);
  memset(memo, -1, sizeof(memo));
  for (int &x : a) {
    cin >> x;
  }
  for (int &x : b) {
    cin >> x;
  }
  int tg = dp(n, m);
  while (n > 0 && m > 0) {
    if (a[n - 1] == b[m - 1]) {
      res.push_back(a[n - 1]);
      n--, m--;
    } else if (memo[n - 1][m] >= memo[n][m - 1]) {
      n--;
    } else {
      m--;
    }
  }
  r::reverse(res);
  cout << tg << el;
  for (int x : res) {
    cout << x << " ";
  }
  cout << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
