#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

bool check(int i) {
  int sum = i * (i + 1) / 2;
  return sum >= i;
}

void solve() {
  int k;
  cin >> k;
  string s = to_string(k);
  int n = s.size();
  vec<string> ss;
  for (int i = 0; i < n; i++) {
    int digit = s[i] - '0';
    int place = n - i - 1;
    int number = digit * pow(10, place);
    if (number != 0)
      ss.push_back(to_string(number));
  }
  cout << ss.size() << el;
  for (string &x : ss) {
    cout << x << " ";
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
