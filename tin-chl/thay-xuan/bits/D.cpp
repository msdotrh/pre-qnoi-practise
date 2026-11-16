#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int count(bitset<64> &bs) {
  int cnt = 0;
  for (int i = 0; i < bs.size(); i++) {
    cnt += bs[i];
  }
  return cnt;
}

void solve() {
  int n;
  cin >> n;
  vec<pair<bitset<64>, int>> bss(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bitset<64> bs(x);
    bss[i] = {bs, count(bs)};
  }
  stable_sort(bss.begin(), bss.end(), [](auto &x, auto &y) {
    int cnt1 = x.second;
    int cnt2 = y.second;
    return cnt1 < cnt2;
  });
  for (auto &x : bss) {
    cout << x.first.to_ullong() << " ";
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
