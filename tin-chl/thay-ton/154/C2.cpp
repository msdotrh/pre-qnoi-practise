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
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int ok = 0;
    for (int j = i + 1; j < n; j++) {
      if (x < a[j]) {
        cout << a[j] << " ";
        ok = 1;
        break;
      }
    }
    if (!ok) {
      cout << -1 << " ";
    }
  }
  cout << el;
}
