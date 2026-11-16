#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<int> a;
vec<bool> v;
int n, m;
int cnt = 0;
int mn = INT_MAX;

void action() {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i] * a[i];
  }
  if (sum >= m) {
    mn = min(mn, sum - m);
  }
}

void s(int ix) {
  for (int j = 0; j <= 1; j++) {
    v[ix] = j;
    if (ix == n - 1) {
      action();
    } else {
      s(ix + 1);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  a.resize(n);
  v.assign(n, 0);
  for (auto &i : a) {
    cin >> i;
  }
  s(0);
  cout << mn << el;
}
