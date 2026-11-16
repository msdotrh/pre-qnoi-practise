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
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  while (n--) {
    int k;
    cin >> k;
    mp[k]++;
  }
  while (m--) {
    int k;
    cin >> k;
    cout << mp[k] << el;
  }
}
