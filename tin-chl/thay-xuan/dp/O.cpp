#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

vec<pair<int, int>> a;

vec<int> memo;
vec<int> visited;

int dp(int p) {
  if (p < 0) {
    return LLONG_MIN;
  }
  if (p - 1 < 0) {
    return a[p].second;
  }
  if (a[p - 1].first >= a[p].first) {
    return a[p].second;
  }
  if (visited[p]) {
    return memo[p];
  }
  visited[p] = 1;
  return memo[p] = max(dp(p - 1) + a[p].second, a[p].second);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  a.resize(n);
  memo.resize(n + 1);
  visited.assign(n + 1, 0);
  for (auto &x : a) {
    cin >> x.first;
  }
  for (auto &x : a) {
    cin >> x.second;
  }
  int res = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    // bat dau chay tai vi tri i
    res = max(res, dp(i));
  }
  cout << res << el;
}
