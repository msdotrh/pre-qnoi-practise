// #include <@msr.h>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
namespace r = ranges;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n, x;
vec<int> a;
unordered_map<int, int> mp;

int dp(int x) {
  if (x == 0) {
    return 0;
  }
  if (x < 0) {
    return LLONG_MAX;
  }
  if (mp.contains(x)) {
    return mp[x];
  }
  int mn = LLONG_MAX;
  for (int i = 0; i < a.size(); i++) {
    int res = dp(x - a[i]);
    if (res != LLONG_MAX) {
      mn = min(mn, res + 1);
    }
  }
  return mp[x] = mn;
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
  vec<int> dp(x + 1, INT_MAX);
  dp[0] = 0;
  for (int xx = 1; xx <= x; xx++) {
    for (int i = 0; i < n; i++) {
      if (a[i] <= xx && dp[xx - a[i]] != INT_MAX) {
        dp[xx] = min(dp[xx], dp[xx - a[i]] + 1);
      }
    }
  }
  cout << (dp[x] == INT_MAX ? -1 : dp[x]);
  cout << el;
}
