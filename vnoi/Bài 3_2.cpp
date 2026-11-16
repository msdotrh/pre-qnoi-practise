// #include <@msr.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

const int MAXN = 1e7;
vec<int> isprime(MAXN + 5, 1);
void pre() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i])
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
  }
}

bool izprime(int x) {
  if (x < 0) {
    return 0;
  }
  return isprime[x];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vec<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    pref[i] = pref[i - 1] + k;
  }
  pre();
  while (q--) {
  }
}
