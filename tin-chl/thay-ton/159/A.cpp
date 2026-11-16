#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

multiset<int> st;

void add() {
  int x;
  cin >> x;
  st.insert(x);
}

void rem() {
  int x;
  cin >> x;
  auto it = st.find(x);
  if (it == st.end()) {
    return;
  }
  st.erase(it);
}

void out() {
  int mn = *st.begin();
  int mx = *st.rbegin();
  cout << mn << " " << mx << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      add();
    } else if (t == 2) {
      rem();
    } else {
      out();
    }
  }
}
