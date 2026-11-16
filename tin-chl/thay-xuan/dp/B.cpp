#include <bits/stdc++.h>
#include <print>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

const int MAXN = 1e4 + 2;

vec<int> sont;
int memo[MAXN];

int lt(int x, int y) {
  if (y == 0) {
    return 0;
  }
  if (y == 1) {
    return x;
  }
  int tg = lt(x, y / 2);
  if (y % 2) {
    return tg * tg * x;
  } else {
    return tg * tg;
  }
}

void pre() {
  bool isprime[MAXN + 5];
  memset(isprime, 1, sizeof(isprime));
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i])
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
  }
  for (int i = 2; i <= MAXN; i++) {
    if (isprime[i]) {
      sont.push_back(i);
    }
  }
  int lim = 1e4 + 2;
  for (int x : sont) {
    int tg = lt(x, x);
    if (tg > lim)
      break;
    sont.push_back(tg);
  }
  r::sort(sont);
}

int dp(int x) {
  if (x == 0)
    return 0;
  if (x < 0)
    return 1e9;
  int &mem = memo[x];
  if (mem != -1) {
    return mem;
  }
  int res = 1e9;
  for (int y : sont) {
    res = min(res, dp(x - y) + 1);
  }
  return mem = res;
}

void solve() {
  int n;
  cin >> n;
  cout << dp(n) << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pre();
  int t;
  cin >> t;
  memset(memo, -1, sizeof(memo));
  while (t--) {
    solve();
  }
}
