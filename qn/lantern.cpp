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

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

const int M = 1e9 + 7;

int mul(int x, int y) { return ((x % M) * (y % M) + M) % M; }
int add(int x, int y) { return ((x % M) + (y % M) + M) % M; }

void solve() {
  int n;
  cin >> n;
  int r = 1;
  int cnt = 0, sum = 0;
  for (int l = 1; l <= n; l = r + 1) {
    int q = n / l;
    r = n / q;
    int k = mul(q, mul(l + r, (r - l + 1))) / 2;
    sum = add(sum, k);
    cnt += (r - l + 1) * q;
  }
  cout << cnt << el << sum << el;
}

void solve(bool ok) {
  int n;
  cin >> n;
  int sum = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int k = n / i;
    cnt += k;
    int u = (k * i) % M;
    sum = (sum + u) % M;
  }
  cout << cnt << el << sum << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
