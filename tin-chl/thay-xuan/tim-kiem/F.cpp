#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

struct tree {
  int a, b;
};

vec<tree> a;
int n, l;
bool check(int x) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].a >= x) {
      sum += 0;
    } else {
      int k = (x - a[i].a + a[i].b - 1) / a[i].b;
      sum += k;
      if (sum > l)
        return 0;
    }
  }
  // du hay thieu
  if (sum > l) {
    // thieu
    return 0;
  } else {
    // du
    return 1;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> l;
  a.assign(n, {0, 0});
  for (tree &x : a) {
    cin >> x.a >> x.b;
  }

  int left = 0, right = 2e18 + 67;
  int ans = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << ans << el;
}
