// #include <@msr.h>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <numeric>
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
  vec<vec<int>> b(4, vec<int>(4));
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 4; j++) {
      b[i][j] = (s[j] == 'b' ? 1 : 0);
    }
  }
  int mn = MAX;
  for (int mask = 0; mask < (1 << 16); mask++) {
    int cnt = 0;
    vec k = b;
    for (int i = 0; i < 16; i++) {
      if (mask >> i & 1) {
        int x = i / 4;
        int y = i % 4;
        k[x][y] ^= 1;
        if (x - 1 >= 0)
          k[x - 1][y] ^= 1;
        if (x + 1 < 4)
          k[x + 1][y] ^= 1;
        if (y - 1 >= 0)
          k[x][y - 1] ^= 1;
        if (y + 1 < 4)
          k[x][y + 1] ^= 1;
        cnt++;
      }
    }
    int sum = accumulate(k.begin(), k.end(), 0, [](int acc, vec<int> &y) {
      return acc + accumulate(y.begin(), y.end(), 0);
    });
    if (sum == 0 || sum == 16) {
      mn = min(mn, cnt);
    }
  }
  if (mn > 16) {
    cout << "Impossible" << el;
  } else {
    cout << mn << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
