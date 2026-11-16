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
  vec<pair<int, int>> hs(n);
  for (int i = 0; i < n; i++) {
    cin >> hs[i].first;
    hs[i].second = i + 1;
  }
  r::sort(hs);
  for (int i = 0; i < n; i++) {
    cout << hs[i].second << " ";
  }
  cout << el;
}
