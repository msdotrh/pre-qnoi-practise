// #include <@msr.h>
#include <cstdio>
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
  freopen("THUGON.INP", "r", stdin);
  freopen("THUGON.OUT", "w", stdout);
  string s;
  while (cin >> s) {
    vec<pair<int, char>> pl;
    char l = s[0];
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (l == s[i]) {
        cnt++;
      } else {
        pl.push_back({cnt, l});
        cnt = 1;
        l = s[i];
      }
    }
    pl.push_back({cnt, l});
    for (auto &i : pl) {
      if (i.first != 1) {
        cout << i.first;
      }
      cout << i.second;
    }
    cout << el;
  }
}
