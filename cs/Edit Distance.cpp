#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll
string s, x;

vec<vec<int>> memo;

int dp(int len1, int len2) {
  if (len1 == 0)
    return len2;
  if (len2 == 0)
    return len1;

  int &mem = memo[len1][len2];
  if (mem != -1) {
    return mem;
  }

  if (s[len1 - 1] == x[len2 - 1]) {
    return mem = dp(len1 - 1, len2 - 1);
  }

  int mn =
      1 + min({dp(len1 - 1, len2), dp(len1, len2 - 1), dp(len1 - 1, len2 - 1)});
  return mem = mn;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s >> x;
  int n = s.size();
  int m = x.size();
  memo.assign(n + 1, vec<int>(m + 1, -1));
  cout << dp(n, m) << el;
}
