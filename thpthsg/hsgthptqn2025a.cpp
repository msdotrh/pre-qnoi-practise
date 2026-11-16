// #include <@msr.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("LATE.INP", "r", stdin);
  freopen("LATE.OUT", "w", stdout);
  long double n, t, m, x, y;
  cin >> n >> t >> m >> x >> y;
  long double t1 = m / x;
  long double t2 = (n - m) / y;
  t *= 60;
  if (t1 + t2 <= t) {
    cout << 0 << el;
    return 0;
  }
  long double mins = (t1 + t2 - t) / 60;
  cout << ceil(mins) << el;
}
