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

vec<vec<int>> a;

void solve() {
  int n;
  cin >> n;
  a.assign(n + 1, vec<int>(6, 0));
  for (auto &x : a) {
    cin >> x[1] >> x[2] >> x[3] >> x[4] >> x[5];
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
