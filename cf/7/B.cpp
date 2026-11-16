#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

stack<int> st;
vec<bool> printed;
void scan(int j) { st.push(j); }
void out(int j) { printed[j] = 1; }
void top(int j) {
  if (st.empty()) {
    out(j);
    return;
  }
  printed[st.top()] = 1;
  st.pop();
}

void solve() {
  st = stack<int>();
  int n;
  cin >> n;
  printed.assign(n + 1, 0);
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    if (s[i] == '1') {
      scan(j);
    } else if (s[i] == '2') {
      top(j);
    } else {
      out(j);
    }
  }
  vec<int> nn;
  for (int i = 1; i <= n; i++) {
    if (!printed[i]) {
      nn.push_back(i);
    }
  }
  cout << nn.size() << el;
  for (int i : nn) {
    cout << i << " ";
  }
  cout << el;
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
