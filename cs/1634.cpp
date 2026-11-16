#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

vec<int> memo;
int dp(int x, vec<int> &c) {
  if (x == 0)
    return 0;
  if (x < 0)
    return INT_MAX;
  if (memo[x] != -1) {
    return memo[x];
  }
  int n = c.size();
  int mn = INT_MAX;
  for (int i = 0; i < n; i++) {
    int k = dp(x - c[i], c);
    if (k != INT_MAX) {
      mn = min(mn, k + 1);
    }
  }
  return memo[x] = mn;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vec<int> c(n);
  for (int &x : c) {
    cin >> x;
  }
  memo.assign(x + 1, -1);
  int d = dp(x, c);
  if (d == INT_MAX) {
    cout << -1 << el;
  } else {
    cout << d << el;
  }
}
