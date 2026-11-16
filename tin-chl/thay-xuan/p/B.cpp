#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<bool> sieve(int x) {
  vec<bool> isprime(x + 5, 1);
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= x; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= x; j += i) {
        isprime[j] = 0;
      }
    }
  }
  return isprime;
}

void solve(vec<bool> &isprime) {
  int k;
  cin >> k;
  cout << (isprime[k] ? "YES" : "NO") << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<bool> isprime = sieve(1e7 + 5);
  for (int i = 0; i < n; i++) {
    solve(isprime);
  }
}
