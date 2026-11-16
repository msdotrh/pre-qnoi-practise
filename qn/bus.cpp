// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
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

int lcm(int x, int y) { return x / gcd(x, y) * y; }

void solve() {
  int a, b, l, r;
  cin >> a >> b >> l >> r;
  int ra = r / a;
  int rb = r / b;
  int la = (l - 1) / a;
  int lb = (l - 1) / b;
  int rla = ra - la;
  int rlb = rb - lb;
  int rab = r / lcm(a, b);
  int lab = (l - 1) / lcm(a, b);
  int rlab = rab - lab;
  int ans = rla + rlb - rlab;
  cout << rlab << el << ans << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
