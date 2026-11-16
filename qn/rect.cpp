// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
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

int m, n;
vec<vec<int>> a;

void solve() {
  cin >> m >> n;
  a.assign(m, vec<int>(n));
  for (auto &x : a) {
    for (auto &y : x) {
      cin >> y;
    }
  }
  int mx = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // vi tri {i, j};
      for (int u = i; u < m; u++) {
        for (int v = j; v < n; v++) {
          int S = (u - i + 1) * (v - j + 1);
          unordered_set<int> st;
          for (int ii = i; ii <= u; ii++) {
            for (int jj = j; jj <= v; jj++) {
              st.insert(a[ii][jj]);
            }
          }
          if (st.size() == S) {
            mx = max(mx, S);
          }
        }
      }
    }
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
