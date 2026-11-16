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

struct pos {
  int x, y;
};

void solve() {
  string s;
  cin >> s;
  pos init{0, 0};
  for (char c : s) {
    if (c == 'L') {
      init.x--;
    } else if (c == 'U') {
      init.y++;
    } else if (c == 'R') {
      init.x++;
    } else {
      init.y--;
    }
  }
  pos goc{0, 0};
  int off = abs(0 - init.x);
  off += abs(0 - init.y);
  int n = s.size();
  int tg = n - off;
  if (tg <= 0) {
    cout << -1 << el;
  } else {
    cout << tg << el;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
