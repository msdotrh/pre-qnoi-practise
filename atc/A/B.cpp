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
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ranges::transform(s, s.begin(), [](char c) { return char(tolower(c)); });
    mp[s]++;
  }
  auto mx = ranges::max_element(
      mp, [](auto i, auto j) { return i.second < j.second; });
  println("{}", mx->second);
}
