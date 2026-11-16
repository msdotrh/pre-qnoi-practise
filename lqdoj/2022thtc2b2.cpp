// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void pr(stack<int> st) {
  while (!st.empty()) {
    cout << (char)st.top() << " ";
    st.pop();
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("ROBOT.INP", "r", stdin);
  freopen("ROBOT.OUT", "w", stdout);
  string s, t;
  cin >> s >> t;
  stack<int> st;
  for (char c : t) {
    if (!st.empty() && st.top() != c) {
      st.pop();
    } else {
      st.push(c);
    }
  }
  int cnt = st.size();
  if (st.top() == 'R') {
    for (int i = s.size() - cnt; i < s.size(); i++) {
      cout << s[i];
    }
    for (int i = 0; i < s.size() - cnt; i++) {
      cout << s[i];
    }
  } else {
    for (int i = cnt; i < s.size(); i++) {
      cout << s[i];
    }
    for (int i = 0; i < cnt; i++) {
      cout << s[i];
    }
  }
  cout << el;
}
