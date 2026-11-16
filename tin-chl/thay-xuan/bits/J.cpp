#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

bool check(int x) {
  bitset<63> bs(x);
  for (int i = 0; i < bs.size() - 1; i++) {
    if (bs[i] == bs[i + 1] && bs[i] == 1) {
      return 1;
    }
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vec<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    pref[i] = pref[i - 1] + check(k);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << el;
  }
}
