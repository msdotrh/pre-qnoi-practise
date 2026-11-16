#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

void solve() {
  string s;
  int n = s.size();
  cin >> s;
  pair<int, int> m = {0, 0};
  for (char c : s) {
    m.first += (c == 'S');
    m.second += (c == 'N');
  }
  int gc = gcd(m.first, m.second);
  cout << m.first / gc << "/" << m.second / gc << el;
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
