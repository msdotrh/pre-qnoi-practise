#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int n, k;
string s;

const int M = 1e9 + 7;

int tinh(int l, int r) {
  int ans = 0;
  for (int i = l; i <= r; i++) {
    ans = ans * 10 + (s[i] - '0');
  }
  return ans;
}

vec<int> memo;

int dp(int i) {
  if (i == -1)
    return 1;
  int res = 0;
  int &mem = memo[i];
  if (mem != -1) {
    return mem;
  }
  for (int j = max(0LL, i - 17); j <= i; j++) {
    int x = tinh(j, i);
    if (x < k) {
      res += dp(j - 1);
      res %= M;
    }
  }
  return mem = res;
}

void solve() {
  cin >> n >> k;
  cin >> s;
  memo.assign(100005, -1);
  cout << dp(n - 1) << el;
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
