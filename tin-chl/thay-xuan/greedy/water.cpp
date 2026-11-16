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

int n, x;

void solve() {
  cin >> n >> x;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  r::sort(a);
  int cnt = 0;
  for (int k : a) {
    if (x - k < 0)
      break;
    x -= k;
    cnt++;
  }
  cout << cnt << el;
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
