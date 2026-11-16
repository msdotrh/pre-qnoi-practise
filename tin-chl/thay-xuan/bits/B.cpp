#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void solve(int n) {
  bitset<63> bs(n);
  if (n == 0) {
    cout << n << el;
    return;
  }
  int i = 0;
  for (; i < bs.size(); i++) {
    if (bs[i]) {
      break;
    }
  }
  cout << (1 << i) << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  while (cin >> t)
    solve(t);
}
