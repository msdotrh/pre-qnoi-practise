#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

#define MAXN 1e6 + 5
int m = 1e9 + 7;
vec<int> spf(MAXN + 5);
void pre() {
  for (int i = 0; i <= MAXN; i++) {
    spf[i] = i;
  }
  for (int i = 2; i <= MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i; j <= MAXN; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  vec<int> ps(MAXN, 0);
  for (int i = a; i <= b; i++) {
    int x = i;
    while (x > 1) {
      ps[spf[x]]++;
      x /= spf[x];
    }
  }
  int cnt = 1;
  for (int i = 2; i <= b; i++) {
    if (ps[i] > 0) {
      cnt *= (2 * ps[i] + 1) % m;
      cnt %= m;
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
  pre();
  while (t--) {
    solve();
  }
}
