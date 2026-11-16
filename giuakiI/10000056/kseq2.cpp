#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

vec<int> a;
vec<int> b;

const int MAXN = 1e18;

int memo[1005][1005][6];

int dp(int i, int j, int x) {
  if (i < 0 || j < 0 || x < 0) {
    return -MAXN;
  }
  if (x == 0) {
    return 0;
  }
  int &mem = memo[i][j][x];
  if (mem != -1) {
    return mem;
  }
  int mx = max({dp(i - 1, j, x), dp(i, j - 1, x),
                dp(i - 1, j - 1, x - 1) + a[i] * b[j]});
  return mem = mx;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  memset(memo, -1, sizeof(memo));
  a.assign(n + 1, 0);
  b.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  cout << dp(n, n, k) << el;
}
