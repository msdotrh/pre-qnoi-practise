#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

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
  vec<int> suff(n + 2, 0);
  dp[n - 1] = 1;
  suff[n - 1] = 1;
  suff[n] = 0;
  for (int i = n - 2; i >= 0; i--) {
    int l = i + 1;
    int r = min(i + a[i], n - 1);
    dp[i] = (suff[l] - suff[r + 1] + M) % M;
    suff[i] = (suff[i + 1] + dp[i]) % M;
  }
  cout << dp[0] << el;
}
