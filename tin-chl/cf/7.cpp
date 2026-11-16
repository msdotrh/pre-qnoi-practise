#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

struct tree {
  int a, h;
};

int t;

void solve() {
  int n;
  cin >> n;
  vec<tree> a(n, {0, 0});
  for (tree &x : a) {
    cin >> x.a;
  }
  for (tree &x : a) {
    cin >> x.h;
  }
  int l = 0;
  int sum = a[l].a;
  int mxs = 0;
  for (int r = 1; r < n; r++) {
    int rr = r - 1;
    if (a[rr].h % a[r].h == 0) {
      // tinh tong
      sum += a[r].a;
    } else {
      l = r;
      mxs = max(mxs, sum);
      sum = a[l].a;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    solve();
  }
}
