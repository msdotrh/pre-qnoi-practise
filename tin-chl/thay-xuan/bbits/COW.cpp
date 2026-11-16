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
  int n, b;
  cin >> n >> b;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int res = MAX;
  for (int x = 0; x < (1 << n); x++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (x >> i & 1) {
        sum += a[i];
      }
    }
    if (sum >= b)
      res = min(res, abs(sum - b));
  }
  cout << res << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
