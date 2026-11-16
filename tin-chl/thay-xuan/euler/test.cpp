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

int m, n;
int cnt = 0;
int conlai = m;
vec<int> slot;

void bt(int i) {
  for (int j = 0; j <= conlai; j++) {
    conlai -= j;
    if (i == n) {
      if (conlai == 0)
        cnt++;
    } else {
      bt(i + 1);
      conlai += j;
    }
  }
}

void solve() {
  cin >> m >> n;
  slot.assign(n, 0);
  bt(0);
  cout << cnt << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
