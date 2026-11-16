#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

struct egg {
  int p, t;
};

int n, x;
vec<egg> a;

bool check(int m) {
  // x giay de duoc bao nhieu qua
  int cnt = 0;
  for (egg y : a) {
    int k = max(0ll, (m - y.p) / y.t + 1);
    cnt += k;
  }
  return cnt >= x;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> x;
  a.resize(n);
  for (egg &x : a) {
    cin >> x.p >> x.t;
  }
  int l = 0, r = 1e18;
  int ans;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  cout << ans << el;
}
