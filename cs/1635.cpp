// #include <@msr.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<int> c;
constexpr int m = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, x;
  cin >> n >> x;
  c.assign(n, 0);
  for (int &x : c) {
    cin >> x;
  }
  vec<int> dp2(x + 1, -1);
  dp2[0] = 1;
  for (int i = 1; i <= x; i++) {
    int k = 0;
    for (int j = 0; j < n; j++) {
      if (i - c[j] >= 0) {
        k += dp2[i - c[j]];
        if (k >= m) {
          k -= m;
        }
      }
    }
    dp2[i] = k;
  }
  cout << dp2[x] << el;
}
