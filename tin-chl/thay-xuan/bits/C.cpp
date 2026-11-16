#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = unsigned long long;
namespace r = ranges;
char el = '\n';
#define int ll

void solve() {
  int p, m;
  cin >> p >> m;
  int x = p ^ m;
  bitset<64> a(x);
  int cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    cnt += a[i];
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
