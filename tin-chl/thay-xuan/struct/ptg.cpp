#include <bits/stdc++.h>
#include <utility>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll
#define MAXN 1000005
vec<bool> isprime(MAXN, 1);
vec<int> primes;
void sieve() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i < MAXN; i++) {
    if (isprime[i]) {
      for (int j = i * i; j < MAXN; j += i) {
        isprime[j] = 0;
      }
    }
  }
  for (int i = 2; i < MAXN; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }
}

vec<pair<int, int>> pt(int x) {
  vec<pair<int, int>> b;
  for (int i = 0; i < primes.size() && primes[i] <= x; i++) {
    int cnt = 0;
    if (x % primes[i] == 0) {
      while (x % primes[i] == 0) {
        x /= primes[i];
        cnt++;
      }
      b.push_back(make_pair(primes[i], cnt));
    }
  }
  if (x != 1) {
    b.push_back(make_pair(x, 1));
  }
  return b;
}

void add(vec<pair<int, int>> &b, map<int, int> &mp) {
  for (auto &i : b) {
    mp[i.first] += i.second;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  sieve();
  map<int, int> mp;
  for (int i = 2; i <= n; i++) {
    vec<pair<int, int>> b = pt(i);
    add(b, mp);
  }
  cout << mp.size() << el;
  for (auto i : mp) {
    cout << i.first << " " << i.second << el;
  }
}
