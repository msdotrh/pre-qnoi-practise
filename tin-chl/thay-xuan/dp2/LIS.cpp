#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> mx;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    auto it = r::lower_bound(mx, x);
    if (it == mx.end()) {
      mx.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << mx.size() << el;
}
