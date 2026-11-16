#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  int n;
  cin >> n;
  int a = 0, b = 0, c = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x % 2 != 0) {
      a++;
    } else {
      if (x % 4 == 0) {
        b++;
      } else {
        c++;
      }
    }
  }
  cout << max({a, b, c}) << el;
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
