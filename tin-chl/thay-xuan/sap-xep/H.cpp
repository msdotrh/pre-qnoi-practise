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
  int l, n;
  cin >> l >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  vec<int> p;
  for (int i = 1; i < n; i++) {
    p.push_back(a[i] - a[i - 1]);
  }
  int mx = *max_element(p.begin(), p.end());
  int res = max({a.front(), l - a.back(), mx / 2});
  cout << res << el;
}
