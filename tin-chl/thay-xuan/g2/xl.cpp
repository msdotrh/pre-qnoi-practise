// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <print>
#include <string>
#include <utility>
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
  vec<pair<int, int>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
  }
  r::sort(a, [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  });
  int curr = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (curr <= a[i].first) {
      curr = a[i].second;
      cnt++;
    }
  }
  cout << cnt << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
