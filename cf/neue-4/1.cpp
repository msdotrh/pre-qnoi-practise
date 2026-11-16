#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = unsigned long long;
char el = '\n';
#define int ll

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int mx = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j < n; j++) {
      mx = max(mx, a[i] ^ a[j]);
    }
  }
  cout << mx << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  /*
3
2
67 67
3
1 2 3
10
67 667 167 867 267 467 367 567 767 967
   */

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
