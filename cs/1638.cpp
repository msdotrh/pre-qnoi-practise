#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

vec<vec<int>> memo;
int m = 1e9 + 7;
int dp(int x, int y, vec<vec<char>> &a) {
  if (x == 0 && y == 0 && a[x][y] != '*') {
    return 1;
  }
  if (x < 0 || y < 0) {
    return 0;
  }
  if (a[x][y] == '*') {
    return 0;
  }
  if (memo[x][y] != -1) {
    return memo[x][y];
  }
  return memo[x][y] = (dp(x - 1, y, a) + dp(x, y - 1, a)) % m;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<vec<char>> a(n, vec<char>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  memo.assign(n, vec<int>(n, -1));
  cout << dp(n - 1, n - 1, a) << el;
}
