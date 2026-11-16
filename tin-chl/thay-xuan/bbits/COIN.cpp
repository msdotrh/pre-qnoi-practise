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

void solve() {
  int n, p;
  cin >> n >> p;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m = n / 2;
  vec<int> b;
  for (int i = m + 1; i < n; i++) {
    b.push_back(a[i]);
  }
  vec<int> a2;
  for (int i = 0; i <= m; i++) {
    a2.push_back(a[i]);
  }
  int le = 0, lo = 0;
  for (int i = 0; i < (1 << a2.size()); i++) {
    int sum = 0;
    for (int j = 0; j < a2.size(); j++) {
      if (i >> j & 1) {
        sum += a2[j];
      }
    }
    if (sum % 2 == 0) {
      le++;
    } else {
      lo++;
    }
  }
  int re = 0, ro = 0;
  for (int i = 0; i < (1 << b.size()); i++) {
    int sum = 0;
    for (int j = 0; j < b.size(); j++) {
      if (i >> j & 1) {
        sum += b[j];
      }
    }
    if (sum % 2 == 0) {
      re++;
    } else {
      ro++;
    }
  }
  const int M = 1e9 + 7;
  int lelele = le * ro + lo * re;
  int chanchanchan = lo * ro + le * re;
  if (p) {
    cout << lelele % M;
  } else {
    cout << chanchanchan % M;
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
