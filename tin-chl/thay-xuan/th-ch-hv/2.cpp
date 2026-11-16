#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll
#define MOD 1000000007

int cnt = 0;
int n, x, y;

void check(vec<int> &a) {
  int xx = 0, yy = 0;
  // check trai

  int mx = -1;
  for (int i = 0; i < n; i++) {
    if (mx < a[i]) {
      xx++;
      mx = a[i];
    }
  }

  // check phai

  mx = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (mx < a[i]) {
      yy++;
      mx = a[i];
    }
  }

  cnt += ((xx == x) & (yy == y));
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> x >> y;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  do {
    check(a);
  } while (next_permutation(a.begin(), a.end()));
  cout << cnt << el;
}
