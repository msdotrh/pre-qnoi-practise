#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

int v(int k) {
  bitset<32> bs(k);
  int i = 0;
  for (; i < bs.size(); i++) {
    if (bs[i]) {
      break;
    }
  }
  return 1 << i;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      sum += v(k);
    }
    cout << sum << el;
  }
}
