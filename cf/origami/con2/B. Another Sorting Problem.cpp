// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int curr = -1;
  vec<int> y;
  for (int i = 0; i < n; i++) {
    if (curr >= a[i]) {
      y.push_back(a[i]);
    }
    curr = max(curr, a[i]);
  }
  if (ranges::is_sorted(y)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << el;
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
