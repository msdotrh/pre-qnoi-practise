// #include <@msr.h>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
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
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  int mn = INT32_MAX;
  int ss = accumulate(a.begin(), a.end(), 0);
  do {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
      sum += a[i];
      int dist = abs(ss - sum);
      mn = min(mn, dist);
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << mn << el;
}
