#include <bits/stdc++.h>
#include <cstdio>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int x, y;

void sub1() { cout << 1 << el; }

void sub67() {
  int cnt = 0;
  for (int i = x; i <= y; i++) {
    for (int j = x; j <= y; j++) {
      for (int k = x; k <= y; k++) {
        for (int l = x; l <= y; l++) {
          if (i * k == j * l) {
            cnt++;
          }
        }
      }
    }
  }
  cout << cnt << el;
}

void sub69() {
  vec<int> f(1e7, 0);
  const int TT = 4e6;
  int cnt = 0;
  for (int i = x; i <= y; i++) {
    for (int j = x; j <= y; j++) {
      int k = i * j + TT;
      f[k]++;
    }
  }
  for (int i : f) {
    cnt += i * i;
  }
  cout << cnt << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("EQUATION.INP", "r", stdin);
  // freopen("EQUATION.OUT", "w", stdout);
  cin >> x >> y;
  if (x == y) {
    sub1();
  } else if (y - x == 1 || (-10 <= x && y <= 10)) {
    sub67();
  } else {
    sub69();
  }
}
