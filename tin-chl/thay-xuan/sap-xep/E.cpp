#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int t, n;
vec<int> x;

int trai(int ind) {
  int c = t;
  int cnt = 0;
  if (ind == 0)
    return 0;
  for (int i = ind - 1; i >= 0; i--) {
    int phi = abs(x[i]);
    c -= phi;
    cout << "phi = " << phi << el;
    cout << "c = " << c << el;
    if (c >= 0) {
      cnt++;
    } else {
      break;
    }
  }
  return cnt;
}

int phai(int ind) {
  int c = t;
  int cnt = 0;
  if (ind == 0)
    return 0;
  for (int i = ind + 1; i < n; i++) {
    int phi = abs(x[i]);
    c -= phi;
    cout << "phi = " << phi << el;
    cout << "c = " << c << el;
    if (c >= 0) {
      cnt++;
    } else {
      break;
    }
  }
  return cnt;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t >> n;
  x.assign(n, 0);
  for (int &y : x) {
    cin >> y;
  }

  sort(x.begin(), x.end());
  int mn = LLONG_MAX;
  int ind;
  for (int i = 0; i < n; i++) {
    int y = x[i];
    if (abs(0 - y) < mn) {
      mn = abs(0 - y);
      ind = i;
    }
  }
  // tim diem bat dau
  cout << mn << "  " << ind << el;

  // 2 huong
  int ans = max(trai(ind), phai(ind));
  cout << ans << el;
}
