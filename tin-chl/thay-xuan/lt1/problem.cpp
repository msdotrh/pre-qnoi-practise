// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T>;
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

int sdg(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

void solve() {
  string s;
  cin >> s;
  string sh = string(s.begin(), s.begin() + 2);
  string sm = string(s.begin() + 3, s.end());
  int x, hh = stoi(sh), mm = stoi(sm);
  cin >> x;
  int cnt = 0;
  for (int h = 0; h < 24; h++) {
    for (int m = 0; m < 60; m++) {
      int phut = m + mm;
      int k = phut / 60;
      int neueh = (h + hh + k) % 24;
      int neuem = phut % 60;
      int s = sdg(neuem) + sdg(neueh);
      if (s % x == 0) {
        cout << cnt << el;
        return;
      }
      cnt++;
    }
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
