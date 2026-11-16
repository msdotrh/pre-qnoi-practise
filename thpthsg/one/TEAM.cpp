// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <map>
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
  int n;
  cin >> n;
  vec<int> a(n);
  vec<int> b(n);
  for (int &x : a) {
    cin >> x;
  }
  for (int &x : b) {
    cin >> x;
  }
  vec<int> k(n);
  for (int i = 0; i < n; i++) {
    k[i] = a[i] - b[i];
  }
  map<int, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    mp[k[i]]++;
  }
  for (int i = 0; i < n; i++) {
    mp[k[i]]--;
    ans += mp[-k[i]];
  }
  cout << ans << el;
}

signed main() {
  io();
  open("TEAM", "TEAM");
  // cin >> t;
  while (t--) {
    solve();
  }
}
