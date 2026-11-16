// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n;
vec<vec<int>> mp;

int lis(vec<int> &a, int i, int p) {
  if (i == a.size()) {
    return 0;
  }

  if (mp[i][p + 1] != -1) {
    return mp[i][p + 1];
  }

  int no = lis(a, i + 1, p);
  int yes = 0;
  if (p == -1 || a[i] > a[p]) {
    yes = 1 + lis(a, i + 1, i);
  }

  return mp[i][p + 1] = max(no, yes);
}

void lis_b(vec<int> &a) {
  vec<int> b;
  for (int x : a) {
    auto it = ranges::lower_bound(b, x);
    if (it == b.end()) {
      b.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << b.size() << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vec<int> a(n);
  mp.assign(n + 1, vec<int>(n + 1, -1));
  for (int &x : a) {
    cin >> x;
  }
  lis_b(a);
}
