#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int c1, c2;
  cin >> c1 >> c2;
  vec<int> a(n);
  vec<int> b(m);
  for (int &x : a) {
    cin >> x;
  }
  for (int &x : b) {
    cin >> x;
  }
  ranges::sort(a);
  ranges::sort(b);
  int ans = abs(c1 - c2);
  int mmb = LLONG_MAX;
  for (int x : a) {
    int mn = LLONG_MAX;
    int high = ranges::lower_bound(b, x) - ranges::begin(b);
    int low = high - 1;
    if (low == -1) {
      mn = abs(x - a[high]);
    } else if (high == m) {
      mn = abs(x - a[low]);
    } else {
      mn = min(x - a[high], x - a[low]);
    }
    mmb = min(mmb, mn);
  }
  ans += mmb;
  cout << ans << el;
}
