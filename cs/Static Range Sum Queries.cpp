// #include <@msr.h>
#include <iostream>
#include <numeric>
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
  int n, q;
  cin >> n >> q;
  vec<int> a(n);
  for (int &x : a)
    cin >> x;
  vec<int> pref(n + 1);
  partial_sum(a.begin(), a.end(), pref.begin() + 1);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << (pref[b] - pref[a - 1]) << el;
  }
}
