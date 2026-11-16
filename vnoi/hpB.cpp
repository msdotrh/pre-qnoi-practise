// #include <@msr.h>
#include <cctype>
#include <iostream>
#include <string>
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
  string s;
  cin >> s;
  int cnt = 0;
  for (char c : s) {
    if (isdigit(c)) {
      cnt++;
    }
  }
  cout << cnt << el;
}
