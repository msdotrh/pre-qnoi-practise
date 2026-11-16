#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n, w;
vec<int> a;

bool check(int m) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= m) {
      // out
    } else {
      sum += m - a[i];
      if (sum > w) {
        return 0;
      }
    }
  }
  return sum <= w;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> w;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  int l = 1;
  int r = *max_element(a.begin(), a.end()) + w;
  int ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << el;
}
