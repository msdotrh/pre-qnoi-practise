#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// freopen("zarkov.inp", "r", stdin);
// freopen("zarkov.out", "w", stdout);

bool scp(ll x) {
  ll r = sqrt(x);
  return r * r == x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, x, k;
  cin >> n >> x;

  bool found = false;

  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (k > x && scp(x)) {
      found = true;
      cout << k << ' ';
    }
  }

  if (!found) {
    cout << -1;
  }

  return 0;
}
