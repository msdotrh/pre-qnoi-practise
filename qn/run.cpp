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
template <typename T>
using vec = vector<T>;
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
  int n, L, S;
  cin >> n >> L >> S;
  vec<int> a(n);
  for (int& x : a) cin >> x;
  vec<int> pref(n + 1, 0);
  partial_sum(a.begin(), a.end(), pref.begin() + 1);
  auto sub1 = [&] {
    int cnt = 0;
    for (int l = 1; l <= n; l++) {
      for (int r = l; r <= n; r++) {
        int sz = r - l + 1;
        int s = pref[r] - pref[l - 1];
        if (sz <= L && s >= S) {
          cnt++;
        }
      }
    }
    return cnt;
  };

  auto sub2 = [&]() {
    int cnt = 0;
    for (int l = 1; l <= n; l++) {
      auto it = r::lower_bound(pref, S + pref[l - 1]);
      if (it == pref.end()) break;
      int rmin = it - r::begin(pref);
      int rmax = n;
      if (rmax >= rmin) {
        int sz = rmax - rmin + 1;
        cnt += sz;
      }
    }
    return cnt;
  };
  /*
  if (sub1() == sub2()) {
    cout << "TRUE" << el;
  } else {
    cout << "FALSE" << el;
  }
  cout << "sub1 : " << sub1() << el;
  cout << "sub2 : " << sub2() << el;
  */
  if (n <= 5000)
    cout << sub1() << el;
  else
    cout << sub2() << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
