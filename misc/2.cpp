#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int luythua(int a, int x) {
  int p = 1;
  for (int i = 0; i < x; i++) {
    p *= a;
  }
  return p;
}

bool check(int x, int k) {
  string s = to_string(x);
  int sum = 0;
  for (char c : s) {
    sum += luythua(c - '0', k);
  }
  return sum == x;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int k;
  cin >> k;
  int cnt = 0;
  for (int i = luythua(10, k - 1); i <= luythua(10, k) - 1; i++) {
    if (check(i, k)) {
      cnt++;
    }
  }
  cout << cnt << el;
}
