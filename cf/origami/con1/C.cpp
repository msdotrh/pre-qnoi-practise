#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
  vec<int> a(2 * n);
  for (int &x : a) {
    cin >> x;
  }
  int sum{ranges::fold_left(a, 0, [](int sum, int x) { return sum + x; })};
  if (sum % 2) {
    for (int x : a) {
      cout << x << " ";
    }
    cout << el;
    return 0;
  }
  ranges::sort(a, greater<int>{});
  int s1 = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    s1 += x;
  }
  int s2 = 0;
  for (int i = n; i < 2 * n; i++) {
    int x = a[i];
    s2 += x;
  }
  if (s1 == s2) {
    cout << -1 << el;
  } else {
    for (int x : a)
      cout << x << " ";
    cout << el;
  }
}
