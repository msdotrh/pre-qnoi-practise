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
  vec<int> b = a;
  ranges::sort(b);
  if (n % 2 == 0) {
    cout << "Yes" << el;
  } else {
    int ok = 1;
    for (int i = 0; i <= n / 2; i++) {
      int l = a[i];
      int r = a[n - 1 - i];
      if (minmax(l, r) != minmax(b[i], b[n - i - 1])) {
        ok = 0;
        break;
      }
    }

    if (ok)
      cout << "Yes" << el;
    else
      cout << "No" << el;
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
