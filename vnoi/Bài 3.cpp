// #include <@msr.h>
#include <iostream>
#include <print>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n, x;

struct egg {
  int p, t;
};

vec<egg> a;

int solve(int t) {
  // trong x giay, ga de duoc bao nhieu con
  int sum = 0;

  for (auto &y : a) {
    sum += max(0ll, (t - y.p) / y.t + 1);
  }

  return sum;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> x;
  a.resize(n);
  for (auto &x : a) {
    cin >> x.p >> x.t;
  }
  int l = 0, r = 1e18;
  int ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    int res = solve(m);
    if (res >= x) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  cout << ans << el;
}
