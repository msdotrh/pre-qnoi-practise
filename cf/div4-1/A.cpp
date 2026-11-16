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

bool eq(int x, int y, int z) { return x == y && y == z; }

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (eq(a - 1, b + 1, c) || eq(a - 1, b, c + 1) || eq(a + 1, b - 1, c) ||
      eq(a, b - 1, c + 1) || eq(a + 1, b, c - 1) || eq(a, b + 1, c - 1)) {
    cout << "YES" << el;
  } else {
    cout << "NO" << el;
  }
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
