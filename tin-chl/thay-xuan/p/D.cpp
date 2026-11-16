#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

vec<int> isprime(1e7 + 5, 1);
vec<int> pref(1e7 + 6, 0);
vec<int> pref2(1e7 + 6, 0);
void pre() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= 1e7; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= 1e7; j += i) {
        isprime[j] = 0;
      }
    }
  }
  for (int i = 1; i <= 1e7 + 1; i++) {
    pref[i] = pref[i - 1] + (isprime[i] ? i : 0);
    pref2[i] = pref2[i - 1] + isprime[i];
  }
}

void query() {
  int l, r;
  cin >> l >> r;
  cout << fixed << setprecision(2)
       << (long double)(pref[r] - pref[l - 1]) /
              (long double)(pref2[r] - pref2[l - 1])
       << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  pre();
  while (n--) {
    query();
  }
}
