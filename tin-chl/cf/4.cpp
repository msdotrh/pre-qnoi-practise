#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cn = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      cn++;
      i += k - 1;
    }
  }
  cout << cn << el;
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
