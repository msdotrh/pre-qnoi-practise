// #include <@msr.h>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

int n, p;
void sub1(vec<int> &a) {
  ranges::sort(a);
  int ans = INT32_MAX;
  for (int i = 0; i < n - 2; i++) {
    int res = a[i + 2] - a[i];
    ans = min(ans, res);
  }
  cout << ans << el;
}

void sub2(vec<int> &a) {
  ranges::sort(a);
  int mx = 0;
  for (int i = 0; i < n; i += 3) {
    int res = a[i + 2] - a[i];
    mx = max(mx, res);
  }
  cout << mx << el;
}

signed main() {
  cin >> n >> p;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  if (p == 1) {
    sub1(a);
  }
  if (3 * p == n) {
    sub2(a);
  }
}
