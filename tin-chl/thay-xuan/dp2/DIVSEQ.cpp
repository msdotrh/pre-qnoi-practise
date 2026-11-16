// #include <@msr.h>
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

vec<int> a;
vec<int> memo;

int dp(int x) {
  if (x < 0)
    return 0;
  if (x == 1)
    return 1;
  int &mem = memo[x];
  if (mem != -1) {
    return mem;
  }
  if (a[x] > a[x - 1]) {
    // ghep
    return mem = dp(x - 1);
  } else {
    return mem = 1 + dp(x - 1);
  }
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

void solve() {
  int n;
  cin >> n;
  a.resize(n);
  memo.assign(n + 1, -1);
  for (int &x : a) {
    cin >> x;
  }
  cout << dp(n - 1) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
