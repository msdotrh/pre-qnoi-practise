// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <print>
#include <ranges>
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
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> pref(n + 1, 0);
  vec<int> suff(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i - 1] / 2;
  }
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = suff[i + 1] + a[i];
  }
  println("{}\n{}", pref, suff);
  int m = 0, p = 1;
  int i = 1, j = n - 1;
  while (i <= j) {
    if (pref[i] < suff[j]) {
      m++;
      i++;
    } else {
      j--;
      p++;
    }
  }
  cout << m << " " << p << el;
  if (m <= p) {
  }
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
