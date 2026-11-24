#include <bits/stdc++.h>
#define el '\n'
#define pb push_back
#define ti 2i
#define ti1 2i + 1
#define lr2 l + (r - l) / 2
#define lm l, mid
#define mr mid + 1, r
#define ilr ll i, ll l, ll r
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
ll t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  for (ll tt = 1; tt <= t; ++tt) {
    ll n;
    ll x, y;
    ll p, q;
    ll a, b;
    ll r;
    ll s;
    char c;
    cin >> n;
    cin >> x >> c >> y;
    cin >> p >> c >> q;
    cin >> a >> c >> b;
    cin >> r;
    cin >> s;
    vector<pair<ll, ll>> k(n);
    for (ll i = 0; i < n; ++i) {
      ll h1, m1;
      ll h2, m2;
      cin >> h1 >> c >> m1;
      cin >> h2 >> c >> m2;
      k[i].first = h1 * 60 + m1;
      k[i].second = h2 * 60 + m2;
    }
    ll xx = x * 60 + y;
    ll pp = p * 60 + q;
    ll aa = a * 60 + b;
    ll ttt = 2 * r + s;
    ll ans = -1;
    ll ok = false;
    for (ll l = max(pp, aa - r); l <= xx - ttt && !ok; ++l) {
      ll rr = l + ttt;
      for (ll i = 0; i < n; ++i) {
        if ((l >= k[i].second) || (rr <= k[i].first)) {
          ans = i + 1;
          ok = true;
          break;
        }
      }
    }
    cout << "Case " << tt << ": " << ans << el;
  }
  return 0;
}
