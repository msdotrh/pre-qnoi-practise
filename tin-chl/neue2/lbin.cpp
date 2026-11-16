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
  int k;
  cin >> k;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '0')
      continue;
    s.erase(s.begin() + i);
    cnt++;
    bitset<61> bs(s);
    int x = bs.to_ullong();
    cerr << "x : " << x << el;
    if (x <= k) {
      cout << cnt << el;
      return 0;
    }
  }
  int x = bitset<61>{s}.to_ullong();
  while (x > k) {
    x >>= 1;
    cnt++;
  }
  cout << cnt << el;
}
