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
  int n, k;
  cin >> n >> k;
  vec<int> p(14, 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  int ans = 0;
  for (int x = 1; x < (1 << n); x++) {
    int sb1 = 0;
    int tich = 1;
    for (int i = 1; i <= n; i++) {
      if ((x >> (i - 1)) & 1) {
        sb1++;
        tich *= p[i];
      }
    }
    int l = k / tich;
    if (sb1 % 2) {
      ans += l;
    } else {
      ans -= l;
    }
  }
  cout << ans << el;
}
