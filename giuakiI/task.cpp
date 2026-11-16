#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

const int MAXN = 1e6;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("task.inp", "r", stdin);
  freopen("task.out", "w", stdout);
  int n;
  cin >> n;
  vec<int> isprime(MAXN + 5, 1);
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
    }
  }
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> idx;
  for (int i = 1; i <= n; i++) {
    if (isprime[i]) {
      idx.push_back(i);
    }
  }
  int mx = 0;
  vec<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i - 1];
  }
  for (int i = 0; i < idx.size(); i++) {
    for (int j = i; j < idx.size(); j++) {
      int l = idx[i];
      int r = idx[j];
      int k = pref[r] - pref[l - 1];
      mx = max(mx, k);
    }
  }
  cout << mx << el;
}
