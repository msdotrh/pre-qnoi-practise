#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

const int MAXX = 1e4 + 2;
const int MAXK = 1e2 + 2;
const int M = 1e9 + 7;
int memo[MAXX][MAXK];

int dp(int x, int k) {
  if (x == 0) {
    return 1;
  }
  if (x < 0) {
    return 0;
  }
  int &mem = memo[x][k];
  if (mem != -1) {
    return mem;
  }
  int res = 0;
  for (int i = 1; i <= k; i++) {
    res += dp(x - i, k);
    res %= M;
  }
  return mem = res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  memset(memo, -1, sizeof(memo));
  while (t--) {
    int x, k;
    cin >> x >> k;
    cout << dp(x, k) << el;
  }
}
