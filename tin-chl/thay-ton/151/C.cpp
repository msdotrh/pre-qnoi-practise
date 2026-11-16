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
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= 0) {
      // skip
      continue;
    }
    int j;
    int sum = 0;
    bool ok = 1;
    for (j = i; j < n; j++) {
      sum += a[j];
      if (sum <= 0) {
        ok = 0;
        break;
      }
    }
    for (int k = 0; k < j; k++) {
      sum += a[k];
      if (sum <= 0) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cnt++;
    }
  }
  cout << cnt << el;
}
