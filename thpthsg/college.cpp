#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> c(n);
  for (int &x : c) {
    cin >> x;
  }
  r::sort(c);
  auto check = [&](int x) {
    int i = r::lower_bound(c, x) - r::begin(c);
    int cnt = n - i;
    int k = cnt * x;
    return k;
  };
  int mx = 0;
  int mxi = 0;
  for (int i = 0; i <= c.back(); i++) {
    int tg = check(i);
    if (mx < tg) {
      mx = tg;
      mxi = i;
    }
  }
  cout << mx << " " << mxi << el;
}
