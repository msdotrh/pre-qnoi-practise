#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

void solve() {
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    auto check = [&](int x) { return x - x / a[0]; };
    int l = 0, r = 2e18;
    int s = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      if (check(m) >= k) {
        s = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << s << el;
    return;
  }
  if (n == 2) {
    auto check = [&](int x) {
      int m = x / a[0];
      int n = x / a[1];
      int mn = x / lcm(a[0], a[1]);
      return x - (m + n - mn);
    };
    int l = 0, r = 2e18;
    int s = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      if (check(m) >= k) {
        s = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << s << el;
    return;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
