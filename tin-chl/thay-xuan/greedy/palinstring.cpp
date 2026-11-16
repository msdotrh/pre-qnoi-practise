// #include <@msr.h>
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>
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

int n;
string s;
int16_t memo[10004][10004];

int dp(int i, int j) {
  if (s[i] != s[j]) {
    return 0;
  }
  if (i == j) {
    return 1;
  }
  if (j - i == 1) {
    return 0;
  }

  auto &mem = memo[i][j];
  if (mem != -1) {
    return mem;
  }

  return mem = dp(i + 1, j - 1);
}

void solve() {
  cin >> n >> s;
  memset(memo, -1, sizeof(memo));
  string curr;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (dp(i, j)) {
        int sz = j - i + 1;
        if (sz >= mx) {
          string sub = s.substr(i, i - j + 1);
          curr = sub;
        }
        mx = max(mx, sz);
      }
    }
  }
  cout << mx << el << curr << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
