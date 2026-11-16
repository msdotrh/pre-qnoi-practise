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
  int n = s.size();
  for (int i = 0; i < n - 1; i++) {
    cout << s[i] << 'o';
  }
  cout << s.back();
  cout << el;
}
