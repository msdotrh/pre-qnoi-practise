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
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> b(m);
  for (int &x : b) {
    cin >> x;
  }
  ranges::sort(a);
  for (int x : b) {
    int low = ranges::upper_bound(a, x) - ranges::begin(a) - 1;
    int high = ranges::lower_bound(a, x) - ranges::begin(a);

    if (low == -1) {
      cout << abs(x - a[high]);
    } else if (high == n) {
      cout << abs(x - a[low]);
    } else {
      cout << min(abs(x - a[low]), abs(x - a[high]));
    }
    cout << el;
  }
}
