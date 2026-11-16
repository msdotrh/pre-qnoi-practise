#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int n, s;
vec<int> a;
bool d(int x, int i) {
  if (x == s) {
    return 1;
  }
  if (i == n) {
    return 0;
  }
  int take = d(x + a[i], i + 1);
  int notake = d(x, i + 1);
  return max(take, notake);
}

void solve() {
  cin >> n;
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  cin >> s;
  if (d(0, 0)) {
    cout << "YES" << el;
  } else {
    cout << "NO" << el;
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
