// #include <@msr.h>
#include <iostream>
#include <vector>
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
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> v = a;
  for (int i = 0; i < n; i++) {
    v[i] = a[i] % 2 == 0;
  }
  int r = n;
  int sum = 0;
  for (int x : v) {
    if (x == 1) {
      r--;
      sum += r;
    }
  }
  cout << sum << el;
}
