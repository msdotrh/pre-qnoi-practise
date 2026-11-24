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

void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  int cnt = 0;
  for (int x0 = 1; x0 <= n; x0++) {
    for (int y0 = 1; y0 <= m; y0++) {
      int cv = (x0 + y0) * 2;
      if (cv >= p) {
        cnt += (n - x0 + 1) * (m - y0 + 1);
      }
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
