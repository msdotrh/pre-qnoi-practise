#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  ranges::stable_sort(a, ranges::greater{});
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int ai = a[i].first;
    int x = i;
    int s = ai * x + 1;
    sum += s;
  }
  cout << sum << el;
  for (auto x : a) {
    cout << x.second + 1 << " ";
  }
  cout << el;
}
