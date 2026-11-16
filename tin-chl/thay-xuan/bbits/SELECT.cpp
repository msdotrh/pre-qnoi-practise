// #include <@msr.h>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
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
vec<vec<int>> a;
int memo[16][1 << 16];

int tong(int i, int mask) {
  bitset<16> bs{(unsigned)mask};
  int sum = 0;
  for (int j = 0; j < n; j++) {
    if (bs[j]) {
      sum += a[i][j];
    }
  }
  return sum;
}

bool check(int mask) {
  bitset<16> bs{(unsigned)mask};
  return bs.count() == 1;
}

map<pair<int, pair<int, int>>, int> mp;

int dp(int i, int mask, int ttc) {
  int cur = tong(i, mask);
  if (i == 0) {
    return cur;
  }
  int neue = ttc | mask;
  int mx = MIN;
  pair<int, pair<int, int>> trangthai = {i, {mask, ttc}};
  if (mp.count(trangthai)) {
    return mp[trangthai];
  }
  for (int j = 0; j < n; j++) {
    int maskk = 1 << j;
    if ((neue & maskk) == 0) {
      mx = max(mx, dp(i - 1, maskk, neue) + cur);
    }
  }
  return mp[trangthai] = mx;
}

int dp(int i, int mask) {
  if (i < 0)
    return 0;
  int &mem = memo[i][mask];
  if (mem != -1) {
    return mem;
  }
  int mx = MIN;
  for (int j = 0; j < n; j++) {
    if (!(mask & (1 << j))) {
      mx = max(mx, dp(i - 1, mask | (1 << j)) + a[i][j]);
    }
  }
  return mem = mx;
}

void solve() {
  cin >> n;
  a.assign(n, vec<int>(n, 0));
  memset(memo, -1, sizeof(memo));
  for (auto &x : a) {
    for (int &y : x) {
      cin >> y;
    }
  }
  int mx = MIN;

  cout << dp(n - 1, 0) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
