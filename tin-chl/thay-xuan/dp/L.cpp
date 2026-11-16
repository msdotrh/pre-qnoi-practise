#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

const int MAXN = 1e4;
bool isprime[MAXN + 5];
void pre() {
  memset(isprime, 1, sizeof(isprime));
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        isprime[j] = 0;
      }
    }
  }
}

string s;
vec<vec<int>> memo;

bool dp(int l, int r) {
  if (l == r)
    return 1;
  if (r - l == 1) {
    if (s[r] == s[l]) {
      return 1;
    }
    return 0;
  }
  if (s[r] != s[l])
    return 0;
  int &mem = memo[l][r];
  int sub = dp(l + 1, r - 1);
  return mem = sub;
}

void solve() {
  cin >> s;
  int mx = 0;
  int n = s.size();
  memo.assign(n, vec<int>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      bool check = dp(i, j);
      if (check) {
        mx = max(mx, j - i + 1);
      }
    }
  }
  if (isprime[mx]) {
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
