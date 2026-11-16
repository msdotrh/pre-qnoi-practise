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
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  deque<int> dqmx;
  deque<int> dqmn;
  int l = 0;
  int mn = INT32_MAX;
  int limit = *ranges::max_element(a) - *ranges::min_element(a);
  map<int, int> mp;
  for (int r = 0; r < n; r++) {
    int x = a[r];
    while (!dqmn.empty() && a[dqmn.back()] >= x) {
      dqmn.pop_back();
    }
    dqmn.push_back(r);
    while (!dqmx.empty() && a[dqmx.back()] <= x) {
      dqmx.pop_back();
    }
    dqmx.push_back(r);
    int ss = a[dqmx.front()] - a[dqmn.front()];
    mp[ss]++;
    while (mn > ss) {
      // pop
      if (!dqmn.empty() && dqmn.front() == l) {
        dqmn.pop_front();
      }

      if (!dqmx.empty() && dqmx.front() == l) {
        dqmx.pop_front();
      }

      l++;
      mn = ss;
    }
  }
  cout << mp[mn] << el;
}
