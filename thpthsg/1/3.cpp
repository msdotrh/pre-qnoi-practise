#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

const int MAXN = 3e6;
bitset<MAXN + 5> isprime;
vec<int> pref(MAXN + 6, 0);

int ds(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

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
    if (ds(i) % 5 != 0) {
      isprime[i] = 0;
    }
  }
  for (int i = 1; i <= MAXN + 1; i++) {
    pref[i] = pref[i - 1] + isprime[i];
  }
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << pref[r] - pref[l - 1] << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pre();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
