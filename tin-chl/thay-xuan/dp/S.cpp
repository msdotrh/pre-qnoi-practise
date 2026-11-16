#include <bits/stdc++.h>
#include <utility>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int n;
vec<int> a;

pair<int, int> dp(int i) {
  // first - khoi
  // second - hoa chat moi
  if (i == 1) {
    return {a[0] * a[1], (a[0] * a[1]) % 100};
  }
  auto prev = dp(i - 1);
  auto chapnhan = make_pair(prev.first * a[i], (prev.second + a[i]) % 100);
  int hc1 = prev.second - a[i - 1];
  if (hc1 < 0) {
    hc1 += 100;
  }
  auto bo1 = make_pair(prev.first / a[i - 1], hc1);
  int hc2 = prev.second - a[i - 2];
  if (hc2 < 0) {
    hc2 += 100;
  }
  auto bo2 = make_pair(prev.first / a[i - 1], hc2);
}

void solve() {
  cin >> n;
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  cout << dp(n - 1);
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
