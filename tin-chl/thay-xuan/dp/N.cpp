#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int n, m;
string s, x;

vec<vec<int>> memo;

int dp(int ixs, int ixx) {
  if (ixs == 0 || ixx == 0) {
    return 0;
  }
  int &mem = memo[ixs][ixx];
  if (mem != -1) {
    return mem;
  }
  if (s[ixs - 1] == x[ixx - 1]) {
    return mem = 1 + dp(ixs - 1, ixx - 1);
  }
  return mem = max(dp(ixs - 1, ixx), dp(ixs, ixx - 1));
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  cin >> s >> x;
  memo.assign(n + 1, vec<int>(m + 1, -1));
  cout << dp(n, m) << el;
}
