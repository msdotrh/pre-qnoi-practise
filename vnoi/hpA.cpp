// #include <@msr.h>
#include <iostream>
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
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i == n) {
        cnt++;
      } else {
        cnt += 2;
      }
    }
  }
  cout << cnt << el;
}
