#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

const int M = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> dp(n + 1, 0);
  dp[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    int res = 0;
    for (int ix = 1; ix <= a[i] && i + ix < n; ix++) {
      res += dp[i + ix];
      if (res >= M) {
        res -= M;
      }
    }
    dp[i] = res;
  }
  cout << dp[0] << el;
}
