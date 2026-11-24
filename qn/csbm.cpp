// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
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
  int g, l;
  cin >> g >> l;
  if (l % g != 0) {
    cout << -1 << el;
    return;
  }
  int p = g * l;
  int cnt = 0;
  int mn = MAX;
  for (int i = g; i * i <= p; i += g) {
    if (p % i == 0) {
      int x = i, y = p / i;
      if (lcm(x, y) == l && gcd(x, y) == g) {
        int sum = x + y;
        mn = min(mn, sum);
        if (x != y) cnt++;
        cnt++;
      }
    }
  }
  cout << cnt << " " << mn << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
