// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("COUNTDIV.INP", "r", stdin);
  freopen("COUNTDIV.OUT", "w", stdout);
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  unordered_map<int, int> mp;
  mp[0] = 1;
  int cnt = 0;
  int sum = 0;
  for (int x : a) {
    sum += x;
    int r = sum % k;
    cnt += mp[r];
    mp[r]++;
  }
  cout << cnt << el;
}
