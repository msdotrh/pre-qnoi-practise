#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

int m, n;
vec<vec<int>> a;

int check(int i, int j) {
  int cnt = 0;
  // check duoi, phai
  if (j == m - 1 && i == n - 1) {
    return 0;
  } else if (j == m - 1) {
    // khong check phai
    cnt = (a[i + 1][j] == a[i][j]);
  } else if (i == n - 1) {
    // khong check duoi
    cnt = (a[i][j + 1] == a[i][j]);
  } else {
    cnt = (a[i + 1][j] == a[i][j]) + (a[i][j + 1] == a[i][j]);
  }
  return cnt;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  a.assign(n, vec<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int c = 2 * (m + n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt += check(i, j);
    }
  }
  cout << cnt + c;
}
