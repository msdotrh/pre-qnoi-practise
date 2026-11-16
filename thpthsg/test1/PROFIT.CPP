// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

void solve() {
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  unordered_map<int, int> mp;
  mp[0] = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    ans += mp[sum - k];
    mp[sum]++;
  }
  cout << ans << el;
}

signed main() {
  io();
  freopen("PROFIT.INP", "r", stdin);
  freopen("PROFIT.OUT", "w", stdout);
  // cin >> t;
  while (t--) {
    solve();
  }
}
