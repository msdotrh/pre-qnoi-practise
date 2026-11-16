#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, n;
  cin >> t >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end(), [](int a, int b) { return abs(a) < abs(b); });
  int pos = 0;
  int total = 0;
  int ans = 0;
  for (int x : a) {
    int c = abs(pos - x);
    total += c;
    if (total > t) {
      break;
    }
    pos = x;
    ans++;
  }
  cout << ans << el;
}
