// #include <@msr.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = unsigned long long;
char el = '\n';
#define int ll

int cnt = 0;

vec<int> solve(vec<int> &a) {
  int n = a.size();
  vec<int> b(n);
  b[0] = a[0];
  for (int i = 1; i < n; i++) {
    b[i] = a[i] | a[i - 1];
  }
  cnt++;
  return b;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> b = solve(a);
  k--;
  while (k--) {
    b = solve(b);
  }
  for (int x : b) {
    cout << x << " ";
  }
  cout << el;
}
