#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

void solve() {
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  deque<int> dmx;
  deque<int> dmn;
  int l = 0;
  int cnt = 0;
  for (int r = 0; r < n; r++) {
    if (!dmx.empty() && a[dmx.back()] <= a[r]) {
      dmx.pop_front();
    }
    dmx.push_back(r);

    if (!dmn.empty() && a[dmn.back()] >= a[r]) {
      dmn.pop_front();
    }
    dmn.push_back(r);

    while (a[dmx.front()] - a[dmn.front()] > 1) {
      if (dmx.front() == l)
        dmx.pop_front();
      if (dmn.front() == l)
        dmn.pop_front();
      l++;
    }

    int m = r - k + 1;
    if (m >= l) {
      cnt += m - l + 1;
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
