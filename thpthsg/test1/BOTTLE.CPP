// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
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
  int vc = n;
  int ans = n;
  int r = 0;
  while (vc >= k) {
    int neue = vc / k;
    r = vc % k;
    ans += neue;
    vc = neue + r;
  }
  cout << ans << el << vc << el;
}

signed main() {
  io();
  freopen("BOTTLE.INP", "r", stdin);
  freopen("BOTTLE.OUT", "w", stdout);
  // cin >> t;
  while (t--) {
    solve();
  }
}
