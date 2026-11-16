// #include <@msr.h>
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
  freopen("ROBOT.INP", "r", stdin);
  freopen("ROBOT.OUT", "w", stdout);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  // chuan hoa ve 0
  int cmx = x1, cmy = y1;
  x1 -= cmx;
  y1 -= cmy;
  x2 -= cmx;
  y2 -= cmy;
  x2 = abs(x2);
  y2 = abs(y2);
  int mn = min(x2, y2);
  int d = mn;
  d += max(abs(mn - x2), abs(mn - y2));
  cout << d << el;
}
