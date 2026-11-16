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
int M = 1e9 + 7;

int lt(int a, int b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  int tg = lt(a, b / 2) % M;
  if (b % 2 != 0) {
    return (tg * tg) * a % M;
  } else {
    return (tg * tg) % M;
  }
}

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      sum += (a[j] - a[i]) * lt(2, j - i - 1);
      sum %= M;
    }
  }
  cout << sum << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
