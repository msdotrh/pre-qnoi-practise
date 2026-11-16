// #include <@msr.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

struct pp {
  int f;
  int p = -1;
};

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  map<int, pp> mp;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    mp[k].f++;
    if (mp[k].p == -1)
      mp[k].p = i;
  }
  for (auto i : mp) {
    if (i.second.f > 1) {
      cout << i.second.p + 1 << el;
      break;
    }
  }
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
