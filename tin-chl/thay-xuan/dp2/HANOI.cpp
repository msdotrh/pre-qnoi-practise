// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
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
int n;

struct dia {
  int r, w;
};
vec<dia> a(n);

pair<int, int> dp(int x) {
  if (x > n) {
    return {0, 0};
  }
  int sum = a[x].w;
  int ans = 0;
  for (int i = 0; i < x; i++) {
    if (a[i].w > a[x].w) {
    }
  }
  return {ans, sum};
}

void solve() {
  cin >> n;
  a.resize(n);
  for (auto &x : a) {
    cin >> x.r >> x.w;
  }
  r::sort(a, [](dia A, dia B) {
    if (A.r != B.r) {
      return A.r < B.r;
    } else {
      return A.w > B.w;
    }
  });
  for (auto i : a) {
    cout << i.r << " " << i.w << el;
  }
  int sum = dp(n - 1).second;
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
