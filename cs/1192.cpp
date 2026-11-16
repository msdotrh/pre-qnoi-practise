#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int n, m;
vec<string> a;

void convert(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) {
    return;
  }
  if (a[i][j] == '#') {
    return;
  }
  a[i][j] = '#';
  convert(i + 1, j);
  convert(i, j + 1);
  convert(i - 1, j);
  convert(i, j - 1);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        cnt++;
        convert(i, j);
      }
    }
  }
  cout << cnt << el;
}
