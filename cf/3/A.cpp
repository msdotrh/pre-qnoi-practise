#include <bits/stdc++.h
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll
//
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  for (auto chunk : s | views::chunk(k)) {
    bool sub = ranges::all_of(chunk, [](char x) { return x == '1'; });
    if (sub)
      cnt++;
  }
  cout << cnt << el;
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
