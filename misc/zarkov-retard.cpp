#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

bool scp(int x) {
  int r = sqrt(x);
  return r * r == x;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vec<int> a(n);
  for (int &y : a) {
    cin >> y;
  }
  vec<int> b;
  for (int y : a) {
    if (scp(y) && y > x) {
      b.push_back(y);
    }
  }
  if (b.empty()) {
    cout << -1 << el;
  } else {
    for (int y : b) {
      cout << y << " ";
    }
  }
}
