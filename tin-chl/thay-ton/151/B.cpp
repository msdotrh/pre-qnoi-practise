#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

void solve() {
  int a, b, n, s;
  cin >> a >> b >> n >> s;
  int k = min(s / n, a);
  int d = k * n;
  int r = s - d;
  if (r > b) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  cout << el;
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
