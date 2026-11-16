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

void solve() {
  int n, x;
  cin >> n >> x;
  if (x >= n) {
    // linh tinh
    for (int i = 0; i < n; i++) {
      cout << i << " ";
    }
    cout << el;
  } else {
    for (int i = 0; i < x; i++) {
      cout << i << " ";
    }
    for (int i = x + 1; i < n; i++) {
      cout << i << " ";
    }
    cout << x << el;
  }
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
