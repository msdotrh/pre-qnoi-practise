// #include <@msr.h>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("SHIPPER.INP", "r", stdin);
  freopen("SHIPPER.OUT", "w", stdout);
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    mp[k]++;
  }
  int ans = 0;
  for (auto i : mp) {
    if (m >= i.second) {
      ans = max(ans, i.second);
    }
  }

  cout << ans << el;
}
