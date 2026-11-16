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
  int n, k;
  cin >> n >> k;
  int tu = 1, mau = 1;
  for (int i = n - 2 * k + 2; i <= n - k + 1; i++) {
    tu = (tu * i) % M;
  }
  for (int i = 1; i <= k; i++) {
    mau = (mau * i) % M;
  }
  cout << tu << " " << mau << el;
  int ans = tu * lt(mau, M - 2);
  cout << ans % M << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
