// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <utility>
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

int k, a, b;
bool check(int i, int j) {
  // (x + u, y / k);
  // (x / k, y + u);
  // (x + u, y + v);
  bool ok = (i - a) >= 0;
  bool ok2 = (j - b) >= 0;
  // th1:
  if (a % k == 0 && b % k == 0 && ok && j == b / k) {
    return 1;
  } else if (a % k == 0 && b % k == 0 && ok2 && i == a / k) {
    return 1;
  } else if (ok && ok2) {
    return 1;
  } else {
    return 0;
  }
}

void solve() {
  cin >> k >> a >> b;
  int m;
  cin >> m;
  vec<pair<int, int>> inp;
  while (m--) {
    int p, q;
    cin >> p >> q;
    inp.push_back({p, q});
  }
  for (auto [p, q] : inp) {
    if (p - a == q - b && p - a > 0) {
      // cout << "TH1: " << p << " " << q << el;
      cout << "YES" << el;
    } else if (a % k == 0 && b % k == 0 && p == a / k && q == b / k) {
      // cout << "TH2: " << p << " " << q << el;
      cout << "YES" << el;
    } else if (check(p, q)) {
      // cout << "TH3: " << p << " " << q << el;
      cout << "YES" << el;
    } else {
      cout << "NO" << el;
    }
  }
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}

/*
2 3 5
5
4 6
2 3
1 1
2 5
4 7
*/
