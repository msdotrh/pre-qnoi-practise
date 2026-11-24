// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
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
  int n, x, y;
  cin >> n >> x >> y;
  vec<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  auto sub1 = [&] {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int s = a[i] + a[j];
        int d = abs(a[i] - a[j]);
        if (s <= x && d >= y) {
          cnt++;
        }
      }
    }
    return cnt;
  };
  auto sub2 = [&] {
    int cnt = 0;
    r::sort(a);
    for (int i = 0; i < n; i++) {
      auto low = r::lower_bound(a, a[i] + y);
      auto high = r::upper_bound(a, x - a[i]);
      int dist = distance(low, high);
      if (dist < 0) continue;
      cnt += dist;
    }
    return cnt;
  };
  cout << sub2() << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
