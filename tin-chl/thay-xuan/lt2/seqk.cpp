// #include <@msr.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
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

int k, m, n;
const int M = 1e9 + 7;
int memo[5005][5005];
int dp[5005][5005];

int dpp(int i, int curr) {
  if (i == n) return 1;
  if (i > n) return 0;
  int& mem = memo[i][curr];
  if (mem != -1) return mem;
  int cong = 0, tru = 0;
  if (curr - k > 0) tru = dpp(i + 1, curr - k);
  if (curr + k < m) cong = dpp(i + 1, curr + k);
  int sum = (tru + cong) % M;
  return mem = sum;
}

void solve() {
  cin >> k >> m >> n;
  memset(dp, 0, sizeof(dp));
  for (int j = 0; j <= 5000; j++) {
    dp[1][j] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int curr = 1; curr < m; curr++) {
      if (dp[i][curr] == 0) continue;
      if (curr - k > 0) {
        dp[i + 1][curr - k] = (dp[i + 1][curr - k] + dp[i][curr]) % M;
      }
      if (curr + k < m) {
        dp[i + 1][curr + k] = (dp[i + 1][curr + k] + dp[i][curr]) % M;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < m; i++) {
    ans = (ans + dp[n][i]) % M;
  }
  cout << ans << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
