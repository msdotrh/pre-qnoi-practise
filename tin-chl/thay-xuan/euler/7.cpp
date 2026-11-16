// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <print>
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

const int M = 998244353;
const int MAXN = 1e7 + 5;
int lt(int x, int y) {
  if (y == 0)
    return 1;
  if (y == 1)
    return x % M;
  int tg = lt(x, y / 2) % M;
  tg = (tg * tg) % M;
  if (y % 2 == 1) {
    tg = (tg * (x % M)) % M;
  }
  return tg;
}

int f[MAXN + 5];
void pre() {
  f[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    f[i] = (f[i - 1] * i) % M;
  }
}

int c(int k, int n) {
  if (k == 0 || k == n)
    return 1;
  if (k < 0 || k > n)
    return 0;
  int tu = f[n];
  int mau = (f[k] * f[n - k]);
  mau %= M;
  int res = tu * lt(mau, M - 2);
  res %= M;
  return res;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int sum = 0;
  for (int i = 0; i <= m; i++) {
    int l = c(m - 1, m - i * n + k - 1) % M;
    int r = c(i, m) % M;
    int x = (l * r) % M;
    /*
    println("C({}, {}) * C({}, {})", m - 1, m - i * n + k - 1, i, m);
    cout << x << el;
    */
    if (i % 2 == 0) {
      sum = (sum + x) % M;
    } else {
      sum = (sum - x + M) % M;
    }
  }
  cout << sum << el;
}

signed main() {
  io();
  pre();
  cin >> t;
  while (t--) {
    solve();
  }
}
