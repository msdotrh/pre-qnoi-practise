#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int n;
string s;

vec<vec<int>> memo;

int dp(int i, int j) {
  if (i < 0) {
    return 1e18;
  }
  if (i == 0) {
    int ans = 0;
    if (j == 1) {
      ans += s[i] != 'D';
    } else if (j == 2) {
      return ans += s[i] != 'V';
    } else if (j == 3) {
      return ans += s[i] != 'X';
    } else {
      return ans += s[i] != 'T';
    }
    return ans;
  }
  int &mem = memo[i][j];
  if (mem != -1) {
    return mem;
  }
  if (j == 1) {
    return mem =
               min({dp(i - 1, 2), dp(i - 1, 3), dp(i - 1, 4)}) + (s[i] != 'D');
  } else if (j == 2) {
    return mem =
               min({dp(i - 1, 1), dp(i - 1, 3), dp(i - 1, 4)}) + (s[i] != 'V');
  } else if (j == 3) {
    return mem =
               min({dp(i - 1, 2), dp(i - 1, 1), dp(i - 1, 4)}) + (s[i] != 'X');
  } else {
    return mem =
               min({dp(i - 1, 2), dp(i - 1, 3), dp(i - 1, 1)}) + (s[i] != 'T');
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  cin >> s;
  memo.assign(n + 1, vec<int>(5, -1));
  int f1 = dp(n - 1, 1);
  int f2 = dp(n - 1, 2);
  int f3 = dp(n - 1, 3);
  int f4 = dp(n - 1, 4);
  int mn = min({f1, f2, f3, f4});
  cout << mn << el;
}
