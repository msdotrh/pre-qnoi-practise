#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

int ddg(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int l, r;
  cin >> l >> r;
  vec<pair<int, int>> mp(ddg(9999999), make_pair(INT_MAX, 0));
  for (int i = l; i <= r; i++) {
    int d = ddg(i);
    mp[d] = {min(i, mp[d].first), i};
  }

  int mx = 0;
  for (auto i : mp) {
    int d = i.second - i.first;
    mx = max(d, mx);
  }
  cout << mx << el;
}
