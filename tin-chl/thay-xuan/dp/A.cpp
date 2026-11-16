#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

const int MAXN = 1e6 + 5;

int c[] = {2, 3, 5, 7};
int memo[MAXN];
int dp(int x) {
  if (x == 0) {
    return 0;
  }
  if (x < 0) {
    return 1e9;
  }
  int &mem = memo[x];
  if (mem != -1) {
    return mem;
  }
  int res = 1e9;
  for (int y : c) {
    res = min(res, dp(x - y) + 1);
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
    int x;
    cin >> x;
    int t = dp(x);
    if (t == 1e9) {
      cout << -1 << el;
    } else {
      cout << t << el;
    }
  }
}
