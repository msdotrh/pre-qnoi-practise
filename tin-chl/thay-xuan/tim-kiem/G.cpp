#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n;
bool check(__int128 k) { return k * (k + 1) * (k + 5) / 6 - 1 <= n; }

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  int l = 1, r = n;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << el;
}
