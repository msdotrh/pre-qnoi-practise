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

void open(string file) {
  string x = file + ".inp";
  string y = file + ".out";
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

void solve() {
  int n;
  cin >> n;
  int prev = 0;
  int curr = 1;
  for (int i = 0; i < n - 1; i++) {
    int temp = curr;
    curr = (curr + prev) % M;
    prev = temp;
  }
  cout << prev << el;
}

signed main() {
  io();
  open("fibo");
  // cin >> t;
  while (t--) {
    solve();
  }
}
