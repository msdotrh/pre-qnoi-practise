#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ii = pair<int, int>;
using ll = long long;
char el = '\n';
#define int ll

#define SAFE 5

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vec<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vec<int> mark(n + SAFE, 0);

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    mark[l]++;
    mark[r + 1]--;
  }

  for (int i = 1; i < n; i++) {
    mark[i] = mark[i] + mark[i - 1];
  }

  sort(a.begin(), a.end(), greater<int>());
  sort(mark.begin(), mark.end(), greater<int>());
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += mark[i] * a[i];
  }
  cout << sum << el;
}
