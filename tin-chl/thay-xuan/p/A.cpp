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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<bool> isprime = sieve(n);
  vec<int> primes;
  for (int i = 2; i <= n; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }
  cout << primes.size() << el;
  for (int i : primes) {
    cout << i << " ";
  }
  cout << el;
}
