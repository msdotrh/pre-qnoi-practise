#include <bits/stdc++.h>
#include <cstring>
#include <ranges>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<int> memo(1e7, -1);

int a, b;

int dp(int k) {
  if (k == 1) {
    return a;
  }
  if (k == 2) {
    return b;
  }
  int &mem = memo[k];
  if (mem != -1) {
    return mem;
  }
  return mem = (dp(k - 1) * dp(k - 2)) % 100;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  cin >> a >> b;
  cout << dp(n) << el;
  for (int i = 1; i <= n; i++) {
    cout << i << ": " << memo[i] << el;
  }
}
