#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

#define MAXN 1000005

vec<bool> isprime;
void sieve() {
  isprime.assign(MAXN, 1);
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i < MAXN; i++) {
    if (isprime[i]) {
      for (int j = i * i; j < MAXN; j += i) {
        isprime[j] = 0;
      }
    }
  }
}

struct pos {
  int x, y;
};
int m, n;

int check(vec<vec<int>> &pref, int x) {
  // dem bao nhieu hinh tmdk
  auto pr_2d = [&](pos x, pos y) {
    int sum = pref[x.x][x.y] - pref[y.x - 1][x.y] - pref[x.x][y.y - 1] +
              pref[y.x - 1][y.y - 1];
    return sum;
  };

  int cnt = 0;

  for (int i = 1; i <= n - x + 1; i++) {
    for (int j = 1; j <= m - x + 1; j++) {

      // {i, j} {i + x - 1, j + x - 1}
      pos a = {i, j};
      pos b = {i + x - 1, j + x - 1};
      int s = x * x;
      int sum = pr_2d(b, a);

      cnt += (sum == s);
    }
  }

  return cnt;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  vec<vec<int>> a(n, vec<int>(m));
  sieve();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k;
      cin >> k;
      a[i][j] = isprime[k];
    }
  }

  vec<vec<int>> pref(n + 1, vec<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                   a[i - 1][j - 1];
    }
  }

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << " ";
    }
    cout << el;
  }

  cout << el;
  for (auto &i : pref) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << el;
  }
  */

  int l = 1, r = min(m, n);
  int ans = 0;
  // hinh vuong lon nhat trong a la min(m,n)
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(pref, mid) > 0) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans * ans << el;
}
