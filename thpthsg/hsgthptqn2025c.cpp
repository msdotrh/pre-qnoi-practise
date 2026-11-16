// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n;
vec<int> a;
map<pair<int, int>, int> memo;
int dp(int i, int x) {
  if (i == n)
    return 0;
  if (memo.contains({i, x})) {
    return memo[{i, x}];
  }
  int notake = dp(i + 1, x);
  int take = 0;
  if (x < a[i]) {
    take = a[i] + dp(i + 1, a[i]);
  }
  return memo[{i, x}] = max(take, notake);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("PRIZES.INP", "r", stdin);
  freopen("PRIZES.OUT", "w", stdout);
  cin >> n;
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  // take
  int take = dp(0, a[0]);
  int notake = dp(0, 0);
  int res = max(take, notake);
  cout << res << el;
}
