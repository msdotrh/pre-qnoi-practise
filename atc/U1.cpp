// #include <@msr.h>
#include <bitset>
#include <cstdio>
#include <cstring>
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

int memo[(1 << 16) + 5];
vec<vec<int>> a;
int c[(1 << 16) + 5];

int dp(int mask) {
  if (mask == 0)
    return 0;

  int &mem = memo[mask];
  if (mem != -1)
    return mem;

  // duyet qua tung tap con cua mask
  int res = MIN;
  for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
    int conlai = mask ^ sub;
    res = max(res, c[sub] + dp(conlai));
  }
  return mem = res;
}

void solve() {
  int n;
  memset(memo, -1, sizeof(memo));
  cin >> n;
  a.assign(n, vec<int>(n));
  for (auto &x : a) {
    for (int &y : x) {
      cin >> y;
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    bitset<16> bs{(unsigned)mask};
    for (int i = bs._Find_first(); i < n; i = bs._Find_next(i)) {
      for (int j = bs._Find_next(i); j < n; j = bs._Find_next(j)) {
        c[mask] += a[i][j];
      }
    }
  }
  cout << dp((1 << n) - 1) << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
