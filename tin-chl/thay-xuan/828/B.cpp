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
  int r;
  cin >> r;
  int mx = 0;
  for (int i = 1; i <= r; i++) {
    int a = i;
    int b = sqrt(r * r - a * a);
    mx = max(mx, a * b * 4);
  }
  cout << mx << el;
}
