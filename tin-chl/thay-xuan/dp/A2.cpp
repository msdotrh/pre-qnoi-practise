#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int n, m;

vec<vec<bool>> vis;
vec<vec<long double>> memo;

long double dp(vec<vec<long double>> &a, int i, int j) {
  // i la hang, j larcot
  if (i < 0) {
    return 0;
  }
  if (j == a[0].size()) {
    return 0;
  }
  if (i == a.size()) {
    return 0;
  }
  auto &mem = memo[i][j];
  if (mem != -1) {
    return mem;
  }
  long double curr = a[i][j];
  long double lc1 = dp(a, i - 1, j + 1);
  long double lc2 = dp(a, i, j + 1);
  long double lc3 = dp(a, i + 1, j + 1);
  if (curr < 0) {
    lc1 /= abs(curr);
    lc2 /= abs(curr);
    lc3 /= abs(curr);
  } else {
    lc1 += curr;
    lc2 += curr;
    lc3 += curr;
  }
  return mem = max({lc1, lc2, lc3});
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  vec<vec<long double>> a(m, vec<long double>(n));
  for (auto &x : a) {
    for (auto &y : x) {
      cin >> y;
    }
  }
  vis.assign(m, vec<bool>(n, 0));
  memo.assign(m, vec<long double>(n, -1));
  long double res = LLONG_MIN;
  for (int i = 0; i < m; i++) {
    res = max(res, dp(a, 1, n));
  }
  cout << res << el;
}
