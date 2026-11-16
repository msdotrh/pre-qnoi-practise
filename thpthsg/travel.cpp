// #include <@msr.h>
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
  int n, q;
  cin >> n >> q;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int sz = abs(x - y) + 1;
    int z = sz / 2;
    int z2 = z + 1;
    int res = max(abs(a[x] - a[z]), abs(a[y] - a[z]));
    int res2 = max(abs(a[x] - a[z2]), abs(a[y] - a[z2]));
    cout << min(res, res2) << el;
  }
}
