// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
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

int n, l, r;
vec<int> a;
vec<int> pref;
vec<int> memo;

int dp(int i) {
  if (i > n) {
    return 0;
  }
  int &mem = memo[i];
  if (mem != -1) {
    return mem;
  }
  int mx = dp(i + 1);
  for (int j = l; j <= r; j++) {
    int end = i + j - 1;
    int k = dp(i + j);
    if (end > n)
      break;
    int sum = pref[end] - pref[i - 1];
    int take = sum + k;
    mx = max(mx, take);
  }
  return mem = mx;
}

void solve() {
  cin >> n >> l >> r;
  a.assign(n + 1, 0);
  for (int &x : a | ranges::views::drop(1)) {
    cin >> x;
  }
  pref.assign(n + 1, 0);
  memo.assign(n + 1, -1);
  partial_sum(a.begin(), a.end(), pref.begin());
  cout << dp(1) << el;
}

signed main() {
  io();
  open("ENERGY", "ENERGY");
  // cin >> t;
  while (t--) {
    solve();
  }
}
