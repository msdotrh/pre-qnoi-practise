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

int lt(int x, int y, int m) {
  if (y == 0)
    return 1;
  if (y == 1)
    return x;
  int tg = lt(x, y / 2, m) % m;
  tg = (tg * tg) % m;
  if (y & 1)
    tg = (tg * (x % m)) % m;
  return tg;
}

void solve() {
  int n, k;
  cin >> k >> n;
  if (n == 1) {
    cout << 1 << el;
  } else if (n == 2) {
    cout << k << el;
  } else if (n == 3) {
    cout << k << el;
  } else {
  }
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
