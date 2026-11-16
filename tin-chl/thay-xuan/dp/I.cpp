#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int memo[5005][5005];

string s;
bool dp(int l, int r) {
  if (l - r == 0) {
    return 1;
  }
  if (r - l == 1) {
    if (s[l] == s[r]) {
      return 1;
    }
    return 0;
  }
  if (s[l] != s[r]) {
    return 0;
  }
  int &mem = memo[l][r];
  if (mem != -1) {
    return mem;
  }
  bool sub = dp(l + 1, r - 1);
  return mem = sub;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s;
  int t;
  cin >> t;
  memset(memo, -1, sizeof(memo));
  while (t--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    bool tg = dp(l, r);
    if (tg) {
      cout << "YES" << el;
    } else {
      cout << "NO" << el;
    }
  }
}
