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
const int MAXN = 4e5;
int lt(int x, int y) {
  if (y == 0)
    return 1;
  if (y == 1)
    return x % M;
  int tg = lt(x, y / 2);
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
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  int tu = f[n];
  int mau = f[k] * f[n - k];
  int res = tu * lt(mau, M - 2);
  res %= M;
  return res;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int any = c(m - 1, m + k - 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x = c(m - 1, m - i * n + k - 1) * c(i, m);
    println("C({}, {}) * C({}, {})", m - 1, m - i * n + k - 1, i, m);
    if (i % 2 == 0) {
      sum -= x;
    } else {
      sum += x;
    }
  }
  cout << any - sum << el;
}

signed main() {
  io();
  pre();
  cin >> t;
  while (t--) {
    solve();
  }
}
