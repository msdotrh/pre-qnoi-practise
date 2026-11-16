// #include <@msr.h>
#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

const int MAXN = 1e6;

vec<int> spf(MAXN + 5, 0);
vec<int> digits(MAXN + 5, 0);
vec<int> pref(MAXN + 5, 0);

int sum(int x) {
  int res = 0;
  while (x) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

int ptsum(int x) {
  int res = 0;
  while (x != 1) {
    int s = spf[x];
    res += digits[s];
    x /= s;
  }
  return res;
}

void pre() {
  for (int i = 0; i <= MAXN; i++) {
    spf[i] = i;
  }
  for (int i = 2; i * i <= MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= MAXN; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
  for (int i = 0; i <= MAXN; i++) {
    digits[i] = sum(i);
  }
  for (int i = 1; i <= MAXN; i++) {
    pref[i] = pref[i - 1] + (digits[i] == ptsum(i));
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pre();
  int a, b;
  cin >> a >> b;
  cout << pref[b] - pref[a - 1];
}
