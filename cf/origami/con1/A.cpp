#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  int j = 0;
  int k = 0;
  for (int i{0}; i < n; i++) {
    bool found = 0;
    while (!found && j < m) {
      if (b[j] == a[i]) {
        found = 1;
        k = i + 1;
      }
      j++;
    }
  }
  cout << k << el;
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
