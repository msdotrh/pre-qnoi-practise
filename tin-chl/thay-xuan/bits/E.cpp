#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int count(auto &x) {
  int cnt = 0;
  for (int i = 0; i < x.size(); i++) {
    cnt += x[i];
  }
  return cnt;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  for (int &x : a) {
    int k;
    cin >> k;
    bitset<64> bs(k);
    x = count(bs);
  }
  sort(a.begin(), a.end(), greater<int>());
  cout << accumulate(a.begin(), a.begin() + k, 0) << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
