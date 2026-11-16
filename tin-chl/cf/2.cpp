#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int ind = min_element(a.begin(), a.end()) - a.begin();
  a[ind]++;
  int p =
      accumulate(a.begin(), a.end(), 1, [](int acc, int x) { return acc * x; });
  cout << p << el;
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
