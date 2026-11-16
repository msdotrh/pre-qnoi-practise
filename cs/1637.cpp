// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  string s{to_string(n)};
  int cnt{0};
  while (n != 0) {
    int mx = *max_element(s.begin(), s.end()) - '0';
    n = stoi(s);
    n -= mx;
    s = to_string(n);
    cnt++;
  }
  cout << cnt << el;
}
