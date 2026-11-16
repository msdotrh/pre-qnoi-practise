#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int n, h;
vec<int> a;

map<pair<int, int>, int> memo;

int dp(int i, int j) {
  if (i == n) {
    return 0;
  }

  int notake = dp(i + 1, j);
  int take = 0;

  if (j == -1) {
    take = dp(i + 1, i) + 1;
    return max(take, notake);
  }

  if (memo.contains({i, j})) {
    return memo[{i, j}];
  }

  if (i - j > 1 && abs(a[i] - a[j]) <= h) {
    take = dp(i + 1, i) + 1;
  }

  return memo[{i, j}] = max(take, notake);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> h;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  vec<vec<int>> dpp(n + 1, vec<int>(n + 1, 0));
  dpp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == n) {
        return 0;
      }

      int notake = dpp[i + 1][j];
      int take = 0;

      if (i - j > 1 && abs(a[i] - a[j]) <= h) {
        take = dpp[i + 1][j] + 1;
      }

      int res = max(take, notake);
      dpp[i][j] = res;
    }
  }
  int tg = dpp[0][0];
  if (tg < 2)
    cout << 0 << el;
  else
    cout << tg << el;
}
