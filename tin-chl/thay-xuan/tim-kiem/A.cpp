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
  int n, x;
  cin >> n >> x;
  int cnt = 0;
  while (n--) {
    int k;
    cin >> k;
    cnt += (k == x);
  }
  if (cnt) {
    cout << "YES " << cnt << el;
  } else {
    cout << "NO " << el;
  }
}
