#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';

void solve(vec<int> &l) {
  int mx = 0;
  int S = 0;
  for (int i = 0; i < l.size(); i++) {
    int mn = l[i];
    for (int j = i; j < l.size(); j++) {
      mn = min(mn, l[j]);
      S = (j - i + 1) * mn;
      mx = max(mx, S);
    }
  }
  cout << mx << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    vec<int> l(n);
    for (int &x : l) {
      cin >> x;
    }
    solve(l);
  }
}
