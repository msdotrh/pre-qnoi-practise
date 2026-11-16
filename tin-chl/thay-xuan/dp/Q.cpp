#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<int> len(46, -1);
map<pair<int, int>, int> memo;

int dp(int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return 1;
  }
  if (len[n] != -1) {
    return len[n];
  }
  return len[n] = dp(n - 1) + dp(n - 2);
}

int dp(int n, int k) {
  if (k <= 0)
    return 0;
  if (n == 0)
    return 1;
  if (n == 1)
    return 0;
  int sz1 = dp(n - 1);
  int sz2 = dp(n - 2);
  int l, r;
  if (memo.contains({n, k})) {
    return memo[{n, k}];
  }
  if (sz2 <= k) {
    l = dp(n - 2, sz2);
    r = dp(n - 1, k - sz2);
  } else {
    l = dp(n - 2, k);
    r = 0;
  }
  return memo[{n, k}] = l + r;
}

void solve() {
  int n, k;
  cin >> n >> k;
  cout << dp(n, k) << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
