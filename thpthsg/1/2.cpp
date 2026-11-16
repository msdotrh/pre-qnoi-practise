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
  string s;
  cin >> s;
  int sum = 0;
  for (char c : s) {
    if (isdigit(c)) {
      sum += c - '0';
    }
  }
  if (sum % 2 == 0) {
    cout << "Hard" << sum << el;
  } else {
    cout << "Easy" << sum << el;
  }
}
