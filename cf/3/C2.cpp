#include <bits/stdc++.h>
// #include <@msr.h>
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

  int fs = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == -1)
      a[i] = 1;
    if (a[i] == 1)
      break;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == -1)
      a[i] = 1;
    if (a[i] == 1)
      break;
  }

  for (int x : a) {
    cout << max(x, 0) << " ";
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
