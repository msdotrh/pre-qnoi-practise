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
  string s;
  cin >> s;
  stack<char> st;
  bool ok = 0;
  for (char c : s) {
    if (!st.empty() && st.top() == c) {
      st.pop();
    } else {
      st.push(c);
    }
  }
  string neue;
  while (!st.empty()) {
    neue.push_back(st.top());
    st.pop();
  }
  reverse(neue.begin(), neue.end());
  cout << neue << el;
}
