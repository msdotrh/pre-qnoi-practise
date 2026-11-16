#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<int> t;
vec<int> r;
vec<int> memo;

int dp(int i) {
  if (i == 0) {
    return 0;
  }
  if (i == 1) {
    return t[1];
  }
  int &mem = memo[i];
  if (mem != -1) {
    return mem;
  }
  return mem = min(dp(i - 1) + t[i], dp(i - 2) + r[i - 1]);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  t.resize(n + 1);
  r.resize(n);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> r[i];
  }
  memo.assign(n + 1, -1);
  cout << dp(n) << el;
}
