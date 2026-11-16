#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  vec<string> vs(10);
  vec<vec<bool>> a(10, vec<bool>(10));
  for (int i = 0; i < 10; i++) {
    cin >> vs[i];
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (vs[i][j] == 'X') {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (a[i][j]) {
        if (i == 0 || j == 0 || i == 9 || j == 9) {
          sum += 1;
        } else if (i == 1 || j == 1 || i == 8 || j == 8) {
          sum += 2;
        } else if (i == 2 || j == 2 || i == 7 || j == 7) {
          sum += 3;
        } else if (i == 3 || j == 3 || i == 6 || j == 6) {
          sum += 4;
        } else {
          sum += 5;
        }
      }
    }
  }
  cout << sum << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
