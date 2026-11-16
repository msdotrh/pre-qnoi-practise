// #include <@msr.h>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

int n;
int mn = INT32_MAX;
int ss;
void solve(bitset<20> &bs, vec<int> &a) {
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    if (bs[i]) {
      // take
      sum += a[i];
    }
    cout << bs[i] << " ";
    mn = min(mn, abs(ss - sum));
  }
  cout << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vec<int> a(n);
  ss = accumulate(a.begin(), a.end(), 0);
  for (int &x : a) {
    cin >> x;
  }
  bitset<20> bs;
  for (int i = 0; i <= 1 << n; i++) {
    bs = i;
    solve(bs, a);
  }
}
