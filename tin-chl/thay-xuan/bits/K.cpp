#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = unsigned long long;
namespace r = ranges;
char el = '\n';
#define int ll

void solve() {
  int z, n;
  cin >> z >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  bool found = 1;
  int x = a[1];
  for (int i = 0; i < n; i++) {
    x &= a[i];
  }
  if ((z & x) == 0) {
    cout << "Yes" << el;
  } else {
    cout << "No" << el;
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
