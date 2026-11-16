#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

const int M = 1e9 + 7;

int n;
vec<int> a;
vec<int> memo;
int dp(int i) {
  if (i == n - 1) {
    return 1;
  }
  if (i >= n) {
    return 0;
  }
  int &mem = memo[i];
  if (mem != -1) {
    return mem;
  }
  int res = 0;
  for (int ix = 1; ix <= a[i]; ix++) {
    res += dp(i + ix);
    if (res > M) {
      res -= M;
    }
  }
  return mem = res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  a.assign(n, 0);
  memo.assign(n + 1, -1);
  for (int &x : a) {
    cin >> x;
  }
  cout << dp(0) << el;
}
