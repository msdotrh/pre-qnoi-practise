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
  // dem so phan tu KHONG can nhac len
  vec<int> mx;
  // lis
  for (int i = 0; i < n; i++) {
    int x = a[i];
    auto it = r::lower_bound(mx, x);
    if (it == r::end(mx)) {
      mx.push_back(x);
    } else {
      *it = x;
    }
  }
  vec<int> mx2;
  for (int i = n - 1; i >= 0; i--) {
    int x = a[i];
    auto it = r::lower_bound(mx2, x);
    if (it == r::end(mx2)) {
      mx2.push_back(x);
    } else {
      *it = x;
    }
  }
  int mxsz = max(mx.size(), mx2.size());
  cout << n - mxsz << el;
}
