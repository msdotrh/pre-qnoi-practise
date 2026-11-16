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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vec<int> mx;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    auto it = r::upper_bound(mx, x);
    if (it == mx.end()) {
      mx.push_back(x);
    } else {
      *it = x;
    }
  }
  vec<int> mx1;
  for (int i = n - 1; i >= 0; i--) {
    int x = a[i];
    auto it = r::upper_bound(mx1, x);
    if (it == mx1.end()) {
      mx1.push_back(x);
    } else {
      *(it) = x;
    }
  }
  println("{}\n{}", mx, mx1);
  int mxsz = max(mx.size(), mx1.size());
  cout << n - mxsz << el;
}
