#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    bitset<63> bs(i);
    string s = bs.to_string();
    int x = log2(i);
    string res;
    for (int j = s.size() - 1; j >= s.size() - x - 1; j--) {
      res += s[j];
    }
    reverse(res.begin(), res.end());
    cout << res;
    cout << ' ';
  }
  cout << el;
}
