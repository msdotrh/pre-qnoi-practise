// #include <@msr.h>
#include <bitset>
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

int n, m;
vec<int> a(n);

void solve() {
  cin >> n >> m;
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  int cnt = 1;
  for (int x = 1; x < (1 << n); x++) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (x >> i & 1) {
        res += a[i];
      }
    }
    if (res % m == 0) {
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
