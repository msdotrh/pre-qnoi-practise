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
  vec<int> b(n);
  vec<int> r(n);
  for (int &x : b) {
    cin >> x;
  }
  for (int &x : r) {
    cin >> x;
  }
  ranges::sort(b);
  ranges::sort(r);
  int i = 0, j = 0;
  int mn = INT32_MAX;
  while (i < n && j < n) {
    int x = b[i];
    int y = r[j];
    mn = min(mn, abs(x - y));
    if (x > y) {
      j++;
    } else {
      i++;
    }
  }
  cout << mn << el;
}
