#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

const int MAXN = 2e6 + 5;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, a, b;
  cin >> n >> a >> b;
  vec<int> dih(MAXN + 5, 0);
  for (int i = 1; i <= MAXN; i++) {
    for (int j = i; j <= MAXN; j += i) {
      dih[j]++;
    }
  }
  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    int x = dih[i];
    if (a <= x && x <= b) {
      cnt++;
    }
  }
  cout << cnt << el;
}
