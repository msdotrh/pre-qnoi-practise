// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <print>
#include <string>
#include <unordered_set>
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

const int M = 1e9 + 7;
int n, k, m;
unordered_set<int> hong;
vec<int> memo;

int dp(int i) {
  if (i < 0) return 0;
  if (i == 0) return 1;
  if (hong.contains(i)) return 0;
  int& mem = memo[i];
  if (mem != -1) return mem;

  int sum = 0;
  for (int p = 1; p <= k; p++) {
    sum += dp(i - p);
    if (sum >= M) sum -= M;
  }

  return mem = sum;
}

void solve() {
  cin >> n >> k >> m;
  memo.assign(n + 1, -1);
  if (m != 0) {
    for (int i = 0; i < m; i++) {
      int q;
      cin >> q;
      hong.insert(q);
    }
  }
  vec<int> dp(n + 1, 0);
  vec<int> pref(n + 2, 0);
  pref[1] = 1;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (hong.contains(i)) {
      dp[i] = 0;
      pref[i + 1] = pref[i];
      continue;
    }
    int sum = pref[i] - pref[max(0LL, i - k)];
    // tong tu
    // [i - 1 -> i - k]
    dp[i] = sum;
    pref[i + 1] = pref[i] + dp[i];
    if (pref[i + 1] >= M) pref[i + 1] -= M;
  }
  cout << dp[n] << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
