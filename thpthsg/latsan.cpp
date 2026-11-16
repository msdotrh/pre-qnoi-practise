// #include <@msr.h>
#include <cstdio>
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
  freopen("LATSAN.INP", "r", stdin);
  freopen("LATSAN.OUT", "w", stdout);
  int x, m, n, k;
  cin >> x >> m >> n >> k;
  m *= 100;
  n *= 100;
  m = m / k * k;
  n = n / k * k;
  int p = k * k;
  int u = m * n / p;
  int res = u * x;
  cout << res << el;
}
