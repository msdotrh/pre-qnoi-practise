#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

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
  int res = abs(c1 - c2);
  ranges::sort(a);
  ranges::sort(b);
  int mn = INT32_MAX;
  vec<int> c(n);
  for (int i = 0; i < n; i++) {
    int high = ranges::lower_bound(b, a[i]) - ranges::begin(b);
    int low = high - 1;
    if (low == -1) {
      c[i] = abs(a[i] - b[high]);
    } else if (high == m) {
      c[i] = abs(a[i] - b[low]);
    } else {
      c[i] = min(abs(a[i] - b[low]), abs(a[i] - b[high]));
    }
    mn = min(mn, c[i]);
  }
  cout << res + mn << " ";
  cout << ranges::count(c, mn) << el;
}
