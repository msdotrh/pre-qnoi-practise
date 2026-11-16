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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  // sub1
  if (s == string(n, 'a')) {
    cout << string((n + k - 1) / k, 'a') << el;
    return 0;
  }
  // sub2
  if (k == n) {
    cout << *min_element(s.begin(), s.end()) << el;
    return 0;
  }

  // sub3
}
