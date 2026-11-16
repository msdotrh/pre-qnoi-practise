#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        cnt++;
        n /= i;
      }
      mp[i] = cnt;
    }
  }
  if (n != 1) {
    mp[n] = 1;
  }
  for (auto &i : mp) {
    i.second *= 2;
  }
  int cnt = 1;
  for (auto i : mp) {
    cnt *= i.second + 1;
  }
  cout << cnt << el;
}
