#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  vec<bitset<31>> xb(n);
  vec<int> cnt(33);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    bitset<31> bs{(unsigned long long)k};
    xb[i] = bs;
  }
  for (int i = 0; i < xb[0].size(); i++) {
    for (int j = 0; j < xb.size(); j++) {
      if (xb[j][i] == 1) {
        cnt[i + 1]++;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= 31; i++) {
    int x = 1 >> (i - 1);
    int y = 1 >> cnt[i];
    ans += x * (y - 1);
  }
  cout << ans << el;
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
