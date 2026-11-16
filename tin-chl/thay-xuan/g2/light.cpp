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

void solve() {
  int m, n;
  cin >> m >> n;
  vec<vec<int>> a(m, vec<int>(n));
  for (auto &x : a) {
    for (int &y : x) {
      cin >> y;
    }
  }
  vec<int> k;
  for (auto &x : a) {
    bitset<32> u;
    for (int i = 0; i < n; i++) {
      u[i] = x[i];
    }
    k.push_back(u.to_ullong());
  }
  int mx = 0;
  for (int mask = 0; mask < (1 << (m + n)); mask++) {
    // m la dong, n la cot
    vec kk = k;
    int j;
    for (j = 0; j < m; j++) {
      // bat j dong
      if (mask >> j & 1) {
        kk[j] ^= (1 << n) - 1;
      }
    }
    for (; j < n + m; j++) {
      if (mask >> j & 1) {
        for (int i = 0; i < m; i++) {
          kk[i] ^= (1 << (j - m));
        }
      }
    }
    int p = 0;
    for (int x : kk) {
      p += __builtin_popcountll(x);
    }
    mx = max(mx, p);
  }
  cout << mx << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
