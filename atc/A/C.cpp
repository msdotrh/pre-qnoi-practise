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
  int n;
  cin >> n;
  set<int> st;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    st.insert(k);
  }

  int cur = 0, ans = 0;

  while (!st.empty()) {
    auto it = st.lower_bound(cur);

    auto r = it;
    auto l = (it == st.begin() ? st.end() : prev(it));

    if (r == st.end()) {
      ans += abs(cur - *l);
      cur = *l;
      st.erase(l);
    } else if (l == st.end()) {
      ans += abs(cur - *r);
      cur = *r;
      st.erase(r);
    } else {
      // check 2 truong hop
      int xl = abs(cur - *l);
      int xr = abs(cur - *r);
      if (xl <= xr) {
        ans += xl;
        cur = *l;
        st.erase(l);
      } else {
        ans += xr;
        cur = *r;
        st.erase(r);
      }
    }
  }
  cout << ans << el;
}
