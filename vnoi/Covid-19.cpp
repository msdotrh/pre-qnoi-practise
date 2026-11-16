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
  freopen("BAI1.INP", "r", stdin);
  freopen("BAI1.OUT", "w", stdout);
  int n, a, b;
  cin >> n >> a >> b;
  cout << max(0, a - b) << " " << min(a, n - b) << el;
}
