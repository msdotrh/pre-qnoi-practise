#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

#define MAXN 1e7 + 67
vec<int> isprime(MAXN + 5, 1);
vec<int> pref(MAXN + 10, 0);
void pre() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
    }
  }
  for (int i = 1; i <= MAXN; i++) {
    pref[i] = pref[i - 1] + isprime[i - 1];
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  pre();
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    cout << pref[k] << el;
  }
}
