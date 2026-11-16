#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define priq priority_queue
#define deq deque
#define sta stack
#define vec vector
#define ins insert
using namespace std;

const ll MOD = 998244353;
const ll MXC = 1e7 + 5;

ll comb[MXC];

void combpr() {
  comb[0] = 1;
  for (int i = 1; i < MXC; i++) {
    comb[i] = ((comb[i - 1] % MOD) * (i % MOD)) % MOD;
  }
}

ll __POW(ll a, ll n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return a;
  ll res = __POW(a, n / 2);
  res = (res * res) % MOD;
  if (n % 2 == 0)
    return res % MOD;
  else
    return (res * a) % MOD;
}

ll Ckn(ll k, ll n) {
  if (k < 0 || k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;
  ll x = comb[n] % MOD;
  ll y = ((comb[k] % MOD) * (comb[n - k] % MOD)) % MOD;
  ll C = x * __POW(y, MOD - 2);
  return C % MOD;
}

void query() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  for (int x = 0; x <= m; x++) {
    ll c1 = Ckn(x, m) % MOD;
    ll c2 = Ckn(m - 1, m + k - x * n - 1) % MOD;
    println("C({}, {}) * C({}, {})", m - 1, m - x * n + k - 1, x, m);
    ll cur = (c1 * c2) % MOD;
    cout << cur << '\n';
    if (x % 2 == 0)
      ans = (ans + cur) % MOD;
    else
      ans = (ans - cur + MOD) % MOD;
  }
  cout << ans % MOD << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  combpr();
  ll t;
  cin >> t;
  while (t--) {
    query();
  }
  return 0;
}
