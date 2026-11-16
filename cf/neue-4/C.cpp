#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << el;
    return 0;
  }
  int k = n + 1;
  if (k % 2)
    cout << k << el;
  else
    cout << k / 2 << el;
}
