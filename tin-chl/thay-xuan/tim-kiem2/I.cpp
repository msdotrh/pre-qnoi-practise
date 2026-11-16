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
  int q;
  cin >> q;
  int q2 = q;
  vec<pair<int, int>> vii;
  while (q--) {
    int a, b;
    cin >> a >> b;
    vii.push_back({a, b});
  }
  ranges::sort(vii);
  map<int, int> mp;
  int last = 0;
  for (auto x : vii) {
    int a = x.first;
    int b = x.second;
    mp[last] = a;
    last += b;
  }
  int k;
  cin >> k;
  k--;
  auto it = mp.upper_bound(k);
  it--;
  cout << it->second << el;
}
