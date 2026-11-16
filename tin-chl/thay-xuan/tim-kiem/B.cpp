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
  int n, m;
  cin >> n >> m;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    if (binary_search(a.begin(), a.end(), k)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << el;
  }
}
