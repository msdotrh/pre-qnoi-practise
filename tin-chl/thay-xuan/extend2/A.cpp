// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <print>
#include <string>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void open(string inp, string out) {
  string x = inp + ".inp";
  string y = out + ".out";
  freopen(x.c_str(), "r", stdin);
  freopen(y.c_str(), "w", stdout);
}

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
  string s;
  cin >> s;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (s[i] == 'O' ? 1 : 0);
  }
  vec<int> pref1(n + 1, 0);
  vec pref0 = pref1;
  for (int i = 1; i <= n; i++) {
    pref0[i] = pref0[i - 1] + (a[i - 1] == 0);
    pref1[i] = pref1[i - 1] + (a[i - 1] == 1);
  }
  // println("{}\n{}\n{}\n{}", s, a, pref0, pref1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int ngua = pref1[j] - pref1[i - 1];
      int sap = pref0[j] - pref0[i - 1];
      if (sap * k == ngua) {
        int sz = j - i + 1;
        mx = max(mx, sz);
      }
    }
  }
  cout << mx << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
