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

  int m, n, q;
  cin >> m >> n >> q;

  int pref[m + 4][n + 4];
  memset(pref, 0, sizeof(pref));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int k;
      cin >> k;
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + k;
    }
  }

  /*
  for (auto x : pref) {
    for (int y : x) {
      cout << y << " ";
    }
    cout << el;
  }
  */

  while (q--) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    cout << pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1];
    cout << el;
  }
}
