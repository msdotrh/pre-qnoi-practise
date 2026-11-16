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
  int m, n;
  cin >> m >> n;
  vec<int> a(n);
  vec<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n; i++) {
    m -= a[i];
  }
  cout << m << el;
  int sum = 0;
  int init = c(m + n - 1, n - 1);
  for (int mask = 0; mask < (1 << n); mask++) {
    int sb1 = 0;
    int rm = m;
    for (int i = 0; i < n; i++) {
      int x = 0;
      if (mask >> i & 1) {
        sb1++;
        x += c(n - 1, rm + n - 1);
        rm -= b[i];
      }
      if (sb1 % 2 == 0) {
        sum = (sum + x) % M;
      } else {
        sum = (sum - x + M) % M;
      }
    }
  }
  cout << init << " " << sum << el;
  cout << (init - sum + M) % M << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
