#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<pair<int, int>> fact(int x) {
  vec<pair<int, int>> ps;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        cnt++;
        x /= i;
      }
      ps.push_back({i, cnt});
    }
  }
  if (x > 1) {
    ps.push_back({x, 1});
  }
  return ps;
}

map<int, int> add(vec<pair<int, int>> &a, vec<pair<int, int>> &b) {
  map<int, int> mp;
  for (auto i : a) {
    mp[i.first] += i.second;
  }
  for (auto i : b) {
    mp[i.first] += i.second;
  }
  return mp;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    vec<pair<int, int>> x = fact(a);
    vec<pair<int, int>> y = fact(b);
    map<int, int> mp = add(x, y);
    int cnt = 1;
    for (auto i : mp) {
      cnt *= i.second + 1;
    }
    cout << cnt << el;
  }
}
