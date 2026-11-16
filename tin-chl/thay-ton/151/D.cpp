#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

struct p {
  int a, b;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<p> a(n);
  for (p &x : a) {
    cin >> x.a >> x.b;
  }
  sort(a.begin(), a.end(), [](p a, p b) { return a.b > b.b; });
  int h = 0;
  int s = 0;
  int mn = LLONG_MAX;
  int mx = LLONG_MIN;
  int mxx = LLONG_MIN;
  for (p x : a) {
    // cap nhat
    mn = min(mn, x.a);
    mx = max(mx, x.a);
    s += x.b;
    h = s - (mx - mn);
    mxx = max(mxx, h);
  }
  cout << mxx << el;
}
