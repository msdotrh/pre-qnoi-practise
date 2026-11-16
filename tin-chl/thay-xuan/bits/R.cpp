// #include <@msr.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  string s, x;
  cin >> s >> x;
  set<char> st;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    st.insert(c);
  }
  for (int i = 0; i < x.size(); i++) {
    char c = x[i];
    if (st.contains(c)) {
      cout << "Yes" << el;
      return;
    }
  }
  cout << "No" << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
