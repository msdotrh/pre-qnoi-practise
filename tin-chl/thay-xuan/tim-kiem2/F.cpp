#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

bool check(vec<int> &a, int i) {
  int c = a[i];
  int n = a.size();
  for (int ix = 0; ix < n; ix++) {
    if (ix == i) {
      continue;
    }
    int need = c - a[ix];
    if (need == a[ix]) {
      continue;
    }
    if (ranges::binary_search(a, need)) {
      return true;
    }
  }
  return false;
}

void sub1(int n, vec<int> &a) {
  int cnt = 0;
  for (int k = 0; k < n; k++) {
    int x = a[k];
    bool ok = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (i == k || j == k)
          continue;
        if (a[i] + a[j] == x) {
          ok = 1;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    if (ok) {
      cnt++;
    }
  }
  cout << cnt << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= 150) {
    sub1(n, a);
    return 0;
  }
  ranges::sort(a);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += check(a, i);
  }
  cout << cnt << el;
}
