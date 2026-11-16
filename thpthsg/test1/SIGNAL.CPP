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
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] ^ a[i - 1];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int x = pref[j] ^ pref[i - 1];
      if (x >= k) {
        cnt++;
      }
    }
  }
  cout << cnt << el;
}

signed main() {
  io();
  freopen("SIGNAL.INP", "r", stdin);
  freopen("SIGNAL.OUT", "w", stdout);
  // cin >> t;
  while (t--) {
    solve();
  }
}
