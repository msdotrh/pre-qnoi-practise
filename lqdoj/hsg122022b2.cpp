#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("MULM.inp", "r", stdin);
  freopen("MULM.out", "w", stdout);
  int l, r;
  cin >> l >> r;
  if (l / 2022 < r / 2022 || l % 2022 == 0) {
    cout << 0 << el;
    return 0;
  }
  int ans = 1;
  for (int i = l; i <= r; i++) {
    ans *= i;
    ans %= 2022;
  }
  cout << ans << el;
}
