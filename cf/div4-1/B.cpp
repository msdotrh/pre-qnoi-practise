// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <memory>
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
  string s;
  cin >> s;
  int cnt = 0;
  char color = 'R';
  for (int i = 0; i < n; i++) {
    int c = s[i];
    if (c != color) {
      color = c;
      cnt++;
    }
    color = (color == 'R' ? 'B' : 'R');
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
