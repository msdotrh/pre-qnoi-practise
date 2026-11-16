// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
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
  int sum =
      r::fold_left_first(a, [](int acc, int x) { return acc + x; }).value();
  if (sum <= n) {
    cout << -1 << el;
  } else {
    cout << sum - 1 << el;
  }
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
