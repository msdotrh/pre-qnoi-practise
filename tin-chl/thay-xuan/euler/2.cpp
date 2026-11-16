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
const int MAXN = 1e6;
const int M = 1e9 + 7;

int f[MAXN + 5];

void pre() {
  f[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    f[i] = (f[i - 1] * i) % M;
  }
}

int lt(int a, int b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  int tg = lt(a, b / 2) % M;
  tg = (tg * tg) % M;
  if (b % 2)
    tg = (tg * (a % M)) % M;
  return tg;
}

void solve() {
  int m, n;
  cin >> m >> n;
  int tu = f[m + n - 1];
  int mau = f[m] * f[n - 1];
  int ans = tu * lt(mau, M - 2);
  cout << ans % M << el;
}

signed main() {
  io();
  pre();
  cin >> t;
  while (t--) {
    solve();
  }
}
