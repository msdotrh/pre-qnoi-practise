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
  freopen("TRASUA.INP", "r", stdin);
  freopen("TRASUA.OUT", "w", stdout);
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  if (n >= k) {
    cout << n * b << el;
  } else {
    cout << n * a << el;
  }
}
