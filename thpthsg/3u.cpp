#include <algorithm>
#include <bits/stdc++.h>
#include <print>
#include <ranges>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

const int MAXN = 1e7;

bitset<MAXN + 5> isprime;
vec<int> primes;
vec<int> square;

void pre() {
  isprime.set();
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i])
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
  }
  for (int i = isprime._Find_first(); i <= MAXN; i = isprime._Find_next(i)) {
    primes.push_back(i);
  }
  for (int i : primes) {
    square.push_back(i * i);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pre();
  int l, r;
  cin >> l >> r;
  int j = r::lower_bound(square, r) - r::begin(square) - 1;
  int i = r::upper_bound(square, l) - r::begin(square);
  println("{}", square | ranges::views::take(30));
  cout << j << " " << i << el;
  int sz = j - i + 1;
  cout << sz << el;
}
