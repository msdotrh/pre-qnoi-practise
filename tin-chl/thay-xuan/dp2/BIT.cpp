#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int n, k;

const int M = 1000007;

vec<int> memo;

int p(int i) {
  if (i == 0)
    return 1;
  if (i == 1)
    return 2;
  int tg = p(i / 2);
  if (i % 2 == 0) {
    return ((tg % M) * (tg % M)) % M;
  } else {
    return ((tg % M) * (tg % M) * 2) % M;
  }
}

int dp(int x) {
  if (x < k)
    return p(x) % M;
  if (x == k)
    return ((p(x) % M) - 1 + M) % M;
  int &mem = memo[x];
  if (mem != -1) {
    return mem;
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans = (ans + dp(x - i)) % M;
  }
  return mem = ans;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  memo.assign(1e7, -1);
  cin >> n >> k;
  cout << (p(n) - dp(n) + M) % M << el;
}
