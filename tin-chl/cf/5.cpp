#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int sum(vec<int> &a, int h) {
  int sum = 0;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] > h) {
      return sum;
    }
    sum += h - a[i];
  }
  return sum;
}

bool check(vec<int> &a, int h, int x) {
  int ssum = sum(a, h);
  return ssum <= x;
}

void solve() {
  int n, x;
  cin >> n >> x;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  auto [l, u] = minmax_element(a.begin(), a.end());
  auto [lower, upper] = make_pair(*l, *u);
  upper += x;
  int ans = 0;
  while (lower <= upper) {
    int middle = (upper + lower) / 2;
    if (check(a, middle, x)) {
      lower = middle + 1;
      ans = middle;
    } else {
      upper = middle - 1;
    }
  }
  cout << ans << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
