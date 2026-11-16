#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

#define MAXN 5e4
vec<bool> isprime(MAXN + 5, 1);
vec<int> primebakhi;
void pre() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i])
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
  }
  for (int i = 2; i <= MAXN; i++) {
    bool thoaman = 1;
    if (isprime[i]) {
      int x = i;
      while (x) {
        if (isprime[x] == 0) {
          thoaman = 0;
          break;
        }
        x /= 10;
      }
    } else {
      thoaman = 0;
    }
    if (thoaman) {
      primebakhi.push_back(i);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m;
  cin >> m;
  pre();
  auto it = r::lower_bound(primebakhi, m);
  if (it == r::begin(primebakhi)) {
    cout << 0 << el;
  } else {
    it--;
    cout << *it << el;
  }
}
