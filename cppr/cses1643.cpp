#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int curr = 0, maxx = INT32_MIN;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    curr = max(k, curr + k);
    maxx = max(maxx, curr);
  }
  cout << maxx << el;
}
