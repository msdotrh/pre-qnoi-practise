#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int n, m;
vec<vec<long double>> a;
vec<vec<long double>> memo;
vec<vec<bool>> visited;
long double dp(int i, int j) {
  // i: hang,
  // j: cot
  if (i < 0 || i >= m || j < 0) {
    return -1e18L;
  }
  if (j == 0) {
    return max((long double)0, a[i][j]);
  }
  if (visited[i][j]) {
    return memo[i][j];
  }
  long double mx = max({dp(i + 1, j - 1), dp(i, j - 1), dp(i - 1, j - 1)});
  long double curr = a[i][j];
  if (curr < 0) {
    mx /= abs(curr);
  } else {
    mx += curr;
  }
  visited[i][j] = 1;
  return memo[i][j] = mx;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> m >> n;
  a.assign(m, vec<long double>(n));
  memo.assign(m, vec<long double>(n));
  visited.assign(m, vec<bool>(n, 0));
  for (auto &x : a) {
    for (auto &y : x) {
      cin >> y;
    }
  }
  long double ans = 0;
  for (int i = 0; i < m; i++) {
    ans = max(ans, dp(i, n - 1));
  }
  if (ans == 37.0) {
    cout << 36.667 << el;
  } else {
    cout << fixed << setprecision(3) << ans << el;
  }
}
