// #include <@msr.h>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

const int MAXN = 1e7 + 10;
bitset<MAXN + 5> isprime;

bool ckkk(int x) {
  if (!isprime[x]) {
    return 0;
  }
  bool f = 0;
  for (int i = 0; i <= 9; i++) {
    int k = x * 10 + i;
    if (isprime[k]) {
      f = 1;
      break;
    }
  }
  while (x > 9) {
    x /= 10;
    if (!isprime[x])
      return 0;
  }
  return f;
}

vec<int> pref;
void chkk(vec<int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    a[i] = ckkk(a[i]);
  }
  pref.resize(n + 1);
  partial_sum(a.begin(), a.end(), pref.begin() + 1);
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
}

void solve() {
  int u, v;
  cin >> u >> v;
  cout << pref[v] - pref[u - 1] << el;
}

bool prime(int x) {
  if (x < 2)
    return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

bool ckkk2(int x) {
  if (!prime(x)) {
    return 0;
  }
  bool f = 0;
  for (int i = 0; i <= 9; i++) {
    int k = x * 10 + i;
    if (prime(k)) {
      f = 1;
      break;
    }
  }
  while (x > 9) {
    x /= 10;
    if (!prime(x))
      return 0;
  }
  return f;
}

void sub2(vec<int> &a) {
  pref.assign(a.size() + 1, 0);
  for (int i = 0; i < a.size(); i++) {
    a[i] = ckkk2(a[i]);
  }
  partial_sum(a.begin(), a.end(), pref.begin() + 1);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, t;
  cin >> n;
  vec<int> a(n);
  for (int &x : a)
    cin >> x;
  if (*ranges::max_element(a) > 1e6) {
    sub2(a);
  } else {
    pre();
    chkk(a);
  }
  cin >> t;
  while (t--) {
    solve();
  }
}
