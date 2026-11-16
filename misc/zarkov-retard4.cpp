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
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      cout << i << " ";
    }
  }
  if (n != 1) {
    cout << n << el;
  }
}
