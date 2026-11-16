#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

struct item {
  int c, p;
};

vec<vec<int>> memo;
int dp(vec<item> &item, int cost, int ind) {
  if (ind < 0 || cost == 0) {
    return 0;
  }
  if (memo[cost][ind] != -1) {
    return memo[cost][ind];
  }
  if (item[ind].c > cost) {
    return dp(item, cost, ind - 1);
  }
  int skip = dp(item, cost, ind - 1);
  int take = item[ind].p + dp(item, cost - item[ind].c, ind - 1);
  return memo[cost][ind] = max(skip, take);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vec<item> a(n + 1);
  vec<int> memo1(x + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1].c;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1].p;
  }
  for (auto [c, p] : a) {
    for (int i = x; i >= c; i--) {
      memo1[i] = max(memo1[i - c] + p, memo1[i]);
    }
  }

  cout << memo1[x] << el;
}
