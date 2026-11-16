// #include <@msr.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

void solve() {
  int n;
  cin >> n;
  int cnt = 0, cnt1 = 0;
  vec<int> a(n);
  for (int &x : a) {
    int k;
    cin >> k;
    if (k % 2 == 0) {
      cnt++;
    } else {
      cnt1++;
    }
  }
  cout << cnt * cnt1 << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
