#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

bool check(int t, vec<int> &a, int d, int c) {
  unordered_set<int> us;
  for (int i = 0; i < a.size(); i++) {
    if (i == d || i == c) {
      continue;
    }
    int can = t - a[i];
    if (us.find(can) != us.end()) {
      return 1;
    }
    us.insert(a[i]);
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  ranges::sort(a, greater<int>());
  for (int di = 0; di < n; di++) {
    for (int ci = di + 1; ci < n; ci++) {
      int t = a[di] - a[ci];
      if (check(t, a, di, ci)) {
        cout << a[di] << el;
        return 0;
      }
    }
  }
  cout << "no solution";
  cout << el;
}
