#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll
#define MOD 1000000007
unordered_map<int, int> memo;

int ff(int n) {
  if (memo.count(n))
    return memo[n];
  if (n < 1) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 1;
  }

  int k = n / 2;
  long long a = ff(k - 1);
  long long b = ff(k);
  long long c = ff(k + 1);

  return memo[n] = n % 2 ? (b * b + c * c) % MOD : b * (a + c) % MOD;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;

  cout << ff(n) << el;
}
