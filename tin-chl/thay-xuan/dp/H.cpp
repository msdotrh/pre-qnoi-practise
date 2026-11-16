#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

struct item {
  int v, w;
};

vec<item> a;
int n, m;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  a.resize(n);
  for (auto &x : a) {
    cin >> x.w >> x.v;
  }
  vec<vec<int>> dp(n + 1, vec<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int take = 0;
      if (j - a[i - 1].w >= 0) {
        take = dp[i - 1][j - a[i - 1].w] + a[i - 1].v;
      }
      int notake = dp[i - 1][j];
      int mx = max(take, notake);
      dp[i][j] = mx;
    }
  }
  cout << dp[n][m] << el;
}
