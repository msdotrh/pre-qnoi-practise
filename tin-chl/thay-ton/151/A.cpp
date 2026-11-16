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
  int n, k;
  cin >> n >> k;
  int l = n / k;
  int r = n % k;
  int s = l * (k * (k + 1) / 2) + r * (r + 1) / 2;
  cout << s << el;
}
