#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int d(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int d2(int x) {
  int sum = 0;
  while (x) {
    int y = x % 10;
    sum += y * y;
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
  int cnt = 0;
  for (int i = l; i <= r; i++) {
    int x = d(i);
    int y = d2(i);
    if (gcd(x, y) == 1) {
      cnt++;
    }
  }
  cout << cnt << el;
}
