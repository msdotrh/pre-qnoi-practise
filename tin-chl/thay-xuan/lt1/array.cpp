// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <print>
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

const int M = 1e9 + 7;
inline int mul(int x, int y) {
  int res = (x % M) * (y % M) % M;
  return (res >= 0 ? res : res + M);
}

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  vec<int> t(n);
  for (int& x : a) {
    cin >> x;
  }
  vec<int> am, duong;
  int khong = 0;
  for (int x : a) {
    if (x > 0)
      duong.push_back(x);
    else if (x < 0)
      am.push_back(x);
    else
      khong++;
  }
  r::sort(am);
  r::sort(duong, r::greater{});
  // println("{}\n{}", am, duong);
  if (n > 2) {
    for (int i = 0; i < n; i++) {
      int aj;
      if (a[i] > 0) {
        if (duong.size() == 1) {
          aj = am.back();
        } else if (a[i] == duong.front()) {
          aj = *(duong.begin() + 1);
        } else {
          aj = duong.front();
        }
      } else if (a[i] < 0) {
        if (am.size() == 1) {
          aj = duong.back();
        } else if (a[i] == am.front()) {
          aj = *(am.begin() + 1);
        } else {
          aj = am.front();
        }
      } else {
        aj = 0;
      }
      t[i] = mul(a[i], aj);
    }
  } else {
    // 2 <= n
    cout << mul(mul(a[0], a[1]), 2);
    return;
  }
  // println("{}", t);
  int s = r::fold_left(t, 0LL,
                       [](int acc, int x) { return (acc + (x % M) + M) % M; });
  cout << s << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
