#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vec<int> f(32, 0);
    while (n--) {
      int x;
      cin >> x;
      for (int i = 31; i >= 0; i--) {
        if ((x >> i) & 1) {
          f[i]++;
        }
      }
    }
    cout << max_element(f.begin(), f.end()) - f.begin() << el;
  }
}
