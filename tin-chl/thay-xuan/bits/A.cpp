#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

void solve() {
  int n;
  cin >> n;
  bitset<32> bs(n);
  int cnt = 0;
  for (int i = 0; i < bs.size(); i++) {
    if (bs[i] == 1) {
      cnt++;
    }
  }
  cout << cnt << el;
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
