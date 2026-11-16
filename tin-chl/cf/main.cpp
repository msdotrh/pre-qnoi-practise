#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  string s;
  cin >> s;
  bool ok = (s == "abc" || s == "acb" || s == "bac" || s == "cba");
  cout << (ok ? "YES" : "NO") << el;
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
