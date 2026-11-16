#include <bits/stdc++.h>
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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
      for (int j = i + 1; j <= n; j++) {
        if ((i ^ j) <= n) {
          cnt++;
        }
      }
    }
    cout << cnt << el;
  }
}
