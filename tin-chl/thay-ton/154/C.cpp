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
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  set<int> st;
  vec<int> out;
  for (int i = a.size() - 1; i >= 0; i--) {
    // tim phan tu lon hon
    auto it = st.upper_bound(a[i]);
    if (it == st.end()) {
      out.push_back(-1);
      st.insert(a[i]);
      continue;
    } else {
      out.push_back(*it);
      st.insert(a[i]);
    }
    st.insert(a[i]);
  }
  for (int i = out.size() - 1; i >= 0; i--) {
    cout << out[i] << " ";
  }
  cout << el;
}
