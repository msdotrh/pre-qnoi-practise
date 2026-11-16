#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int n, x;
vec<int> a;
map<pair<int, int>, int> memo;

constexpr int m = 1e9 + 7;

int dp(int x, int ind) {
  if (x == 0) {
    return 1;
  }
  if (x < 0) {
    return 0;
  }
  if (memo.contains({x, ind})) {
    return memo[{x, ind}];
  }
  int sum = 0;
  for (int i = ind; i < n; i++) {
    sum += dp(x - a[i], i) % m;
    sum %= m;
  }
  return memo[{x, ind}] = sum % m;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> x;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> dp(x + 1);
  dp[0] = 1;
  for (int c : a) {
    for (int s = c; s <= x; s++) {
      dp[s] += dp[s - c];
      if (dp[s] >= m)
        dp[s] -= m;
    }
  }
  cout << dp[x] << el;
}
