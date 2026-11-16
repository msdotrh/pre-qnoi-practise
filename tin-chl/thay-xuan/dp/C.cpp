#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

const int M = 123456789;
vec<int> a;

vec<int> memo;

int dp(int x) {
  if (x == 0) {
    // da den
    return 1;
  }
  if (x < 0) {
    return 0;
  }
  int &mem = memo[x];
  if (mem != -1) {
    return mem;
  }
  int cnt = 0;
  for (int y : a) {
    cnt += dp(x - y);
    cnt %= M;
  }
  return mem = cnt;
}

int n, k;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  a.resize(k);
  memo.assign(n + 1, -1);
  for (int &x : a) {
    cin >> x;
  }
  cout << dp(n) << el;
}
