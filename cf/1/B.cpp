#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  int n, k;
  cin >> n >> k;
  // chan
  int s = n - (k - 1) * 2;
  // check tmdk
  if (s % 2 == 0 && s > 0) {
    cout << "YES" << el;
    for (int i = 0; i < k - 1; i++) {
      cout << 2 << " ";
    }
    cout << s << el;
    return;
  }

  // le
  s = n - k + 1;
  // check tmdk
  if (s % 2 && s > 0) {
    cout << "YES" << el;
    for (int i = 0; i < k - 1; i++) {
      cout << 1 << " ";
    }
    cout << s << el;
    return;
  }

  cout << "NO" << el;
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
