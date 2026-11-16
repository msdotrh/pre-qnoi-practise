// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <type_traits>
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

int n, k;
void sub1(vec<int> &a, vec<int> &b) {
  // neu tat ca = -1
  sort(a.begin(), a.end());
  int lower = a.back();
  int upper = a.front() + k;
  int res = max(0ll, upper - lower + 1);
  cout << res << el;
}

void solve() {
  cin >> n >> k;
  vec<int> a(n);
  vec<int> b(n);
  for (int &x : a) {
    cin >> x;
  }
  for (int &x : b) {
    cin >> x;
  }
  bool all = 1;
  bool setted = 1;
  for (int i = 0; i < n; i++) {
    if (b[i] >= 0) {
      all = 0;
    }
    if (b[i] < 0) {
      setted = 0;
    }
  }
  if (all) {
    sub1(a, b);
    return;
  }
  int target = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] >= 0) {
      target = b[i] + a[i];
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] >= 0) {
      int neuetg = b[i] + a[i];
      if (neuetg != target) {
        cout << 0 << el;
        return;
      }
    }
  }
  // tat ca phai ve target
  for (int i = 0; i < n; i++) {
    if (b[i] < 0) {
      int need = target - a[i];
      if (need > k || need < 0) {
        cout << 0 << el;
        return;
      }
    }
  }
  cout << 1 << el;
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
