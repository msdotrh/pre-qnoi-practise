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
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
      continue;
    }
    if (st.empty()) {
      cout << "NO" << el;
      return 0;
    }
    if ((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') ||
        (c == '}' && st.top() != '{')) {
      cout << "NO" << el;
      return 0;
    }
    // tmdk
    st.pop();
  }
  if (st.empty())
    cout << "YES";
  else
    cout << "NO";
}
