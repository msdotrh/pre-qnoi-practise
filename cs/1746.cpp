#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll
#define v(x) vec<int>((x))

constexpr int MOD = 1e9 + 7;

vec<vec<int>> memo;
int dp(int idx, int c, vec<int> &a, int m) {
  int ans = 0;
  if (idx == a.size())
    return 1;
  if (memo[idx][c] != -1) {
    return memo[idx][c];
  }
  if (a[idx] != 0) {
    if (idx == 0 || abs(a[idx] - c) <= 1) {
      ans += dp(idx + 1, a[idx], a, m) % MOD;
      ans %= MOD;
    }
  } else {
    if (idx == 0) {
      for (int i = 1; i <= m; i++) {
        ans += dp(idx + 1, i, a, m) % MOD;
        ans %= MOD;
      }
    } else {
      for (int i = max(1LL, c - 1); i <= min(m, c + 1); i++) {
        ans += dp(idx + 1, i, a, m) % MOD;
        ans %= MOD;
      }
    }
  }
  return memo[idx][c] = ans;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  auto a = v(n);
  memo.assign(n + 1, vec<int>(m + 1, -1));
  for (int &x : a) {
    cin >> x;
  }
  cout << dp(0, 0, a, m) << el;
}
