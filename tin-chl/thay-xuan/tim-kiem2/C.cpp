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
  int n, k, d;
  cin >> n >> k >> d;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  ranges::sort(a);
  int high = ranges::lower_bound(a, k) - ranges::begin(a);
  int low = high - 1;
  int ans;
  if (low == -1) {
    ans = abs(k - a[high]);
  } else if (high == n) {
    ans = abs(k - a[low]);
  } else {
    ans = min(abs(k - a[high]), abs(k - a[low]));
  }
  if (ans > d) {
    cout << "NO " << ans - d;
  } else {
    cout << "YES";
  }
  cout << el;
}
