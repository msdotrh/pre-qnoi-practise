// #include <@msr.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

int dp(int x) {
  if (x <= 0)
    return 0;
  if (x == 1)
    return 1;
  if (x == 2)
    return 1;
  if (x == 3)
    return 2;
}

void solve() {
  int s;
  cin >> s;
  cout << dp(s);
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
