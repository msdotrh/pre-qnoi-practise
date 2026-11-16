#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vec<int> pos = a;
  ranges::sort(a);
  for (int x : pos) {
    int it = lower_bound(a.begin(), a.end(), x) - a.begin();
    cout << it << " ";
  }

  cout << el;
}
