#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

string check(int k) {
  if (k == 0) {
    return "No";
  }
  while (k % 2 == 0) {
    k /= 2;
  }
  return (k == 1) ? "Yes" : "No";
}

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    sum += k * (k >= 0);
  }
  cout << check(sum) << el;
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
