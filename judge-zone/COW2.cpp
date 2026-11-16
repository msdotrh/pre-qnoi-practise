#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c{}, co{}, cow{};
  for (char cx : s) {
    if (cx == 'C') {
      c++;
    } else if (cx == 'O') {
      co += c;
    } else {
      cow += co;
    }
  }
  cout << cow << el;
}
