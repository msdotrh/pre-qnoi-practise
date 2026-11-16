#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

struct hs {
  int a, b;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, c, k;
  cin >> n >> c >> k;
  vec<int> l;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a >= k) {
      cnt++;
    } else if (b == 0) {
      continue;
    } else {
      l.push_back((k - a + b - 1) / b);
    }
  }
  sort(l.begin(), l.end());
  for (int i = 0; i < l.size(); i++) {
    c -= l[i];
    if (c < 0) {
      break;
    } else {
      cnt++;
    }
  }
  cout << cnt << el;
}
