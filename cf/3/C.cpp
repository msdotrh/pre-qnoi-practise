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
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int low = a + c;
  int high = b + d;
  int sum = high / k * k;
  if (sum < low) {
    cout << -1 << el;
    return 0;
  }

  int x = min(b, sum - c);
  int y = sum - x;

  if (a <= x && x <= b && c <= y && y <= d) {
    cout << x << " " << y << el;
    return 0;
  }
  cout << -1;
}
