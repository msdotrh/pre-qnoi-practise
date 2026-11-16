// #include <@msr.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
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
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  set<int> st;
  ranges::sort(a, greater<int>{});
  for (int i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      if (i * i == k) {
        st.insert(i);
      } else {
        st.insert(i);
        st.insert(k / i);
      }
    }
  }
  for (int x : a) {
    if (st.count(x)) {
      // find
      cout << k / x << el;
      return 0;
    }
  }
  cout << -1 << el;
}
