#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

const int MAXN = 1e3 + 5;
bool isprime[MAXN];
void pre() {
  memset(isprime, 1, sizeof(isprime));
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i])
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
  }
}

string s;
int dp(int l, int r) {
  if (l - r == 0)
    return 1;
  if (l > r)
    return 0;
  if (s[l] == s[r]) {
    return 2 + dp(l + 1, r - 1);
  } else {
    return max(dp(l, r - 1), dp(l + 1, r));
  }
}

void solve() {
  cin >> s;
  int len = dp(0, s.size() - 1);
  cout << len << el;
  if (isprime[len]) {
    cout << "YES" << el;
  } else {
    cout << "NO" << el;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  pre();
  while (t--) {
    solve();
  }
}
