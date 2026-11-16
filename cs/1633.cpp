#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int m = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> dp(n + 1, -1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        sum += dp[i - j] % m;
        sum %= m;
      }
    }
    dp[i] = sum % m;
  }
  cout << dp.back() << el;
}
