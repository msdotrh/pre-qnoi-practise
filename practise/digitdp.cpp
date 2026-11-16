// #include <@msr.h>
#include <cstring>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

const int MAXN = 50;

int memo[20][20][2][2];
int dp(string_view s, int curr, int prev, bool tight, bool lead) {
  if (curr == s.size()) {
    return 1;
  }

  int &mem = memo[curr][prev][tight][lead];
  if (mem != -1) {
    return mem;
  }

  int l = 0;
  int r;
  if (tight) {
    r = s[curr] - '0';
  } else {
    r = 9;
  }

  int res = 0;
  for (int i = l; i <= r; i++) {
    if (!lead && prev == i) {
      continue;
    }
    res += dp(s, curr + 1, i, tight && i == s[curr] - '0', (lead && i == 0));
  }
  return mem = res;
}

int dp(int x) {
  if (x < 0)
    return 0;

  string s = to_string(x);
  memset(memo, -1, sizeof(memo));

  return dp(s, 0, 10, 1, 1);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  cout << dp(b) - dp(a - 1) << el;
}
