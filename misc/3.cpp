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
  string s, x;
  cin >> s >> x;
  int cnt = 0;
  for (int i = 0; i + x.size() <= s.size(); i++) {
    if (s.substr(i, x.size()) == x) {
      cnt++;
    }
  }
  cout << cnt << el;
}
