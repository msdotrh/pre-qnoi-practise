#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

bool check(int k) {
  if (k == 0)
    return 0;
  while (k % 2 == 0)
    k /= 2;
  return k == 1;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    int k;
    cin >> k;
    cnt += check(k);
  }
  cout << cnt << el;
}
