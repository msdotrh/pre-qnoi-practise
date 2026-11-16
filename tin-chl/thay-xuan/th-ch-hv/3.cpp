#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

int m = 1e9 + 7;

int lt(int a, int x) {
  a %= m;
  if (x == 0)
    return 1;
  if (x == 1)
    return a;
  int k = lt(a, x / 2) % m;
  if (k % 2) {
    return (k * k % m) * a % m;
  } else {
    return k * k % m;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int A, n;
  cin >> A >> n;
  int a = (lt(A, n + 1) - 1 + m) % m;
  int b = (lt(A - 1, m - 2)) % m;
  int t = a * b;
  cout << t << el;
}
