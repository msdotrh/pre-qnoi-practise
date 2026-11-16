#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

#define MAXN 1e6
vec<int> divs(MAXN + 5, 1);
void pre() {
  for (int i = 2; i <= MAXN; i++) {
    for (int j = i; j <= MAXN; j += i) {
      divs[j]++;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int gc = a[0];
  for (int i = 1; i < n; i++) {
    gc = gcd(gc, a[i]);
  }
  cout << divs[gc] << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  pre();
  while (t--) {
    solve();
  }
}
