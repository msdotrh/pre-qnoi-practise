#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<bool> visited(n, 0);
  map<int, int> mp;
  for (int i = 0; i < n - 4; i++) {
    int k = a[i] + a[i + 2] - a[i + 4];
    mp[k]++;
  }
  int ans = 0;
  for (auto i : mp) {
    ans += i.second * (i.second - 1) / 2;
  }
  cout << ans << el;
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
