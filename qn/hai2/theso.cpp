// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <istream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

void open(string inp, string out) {
  string x = inp + ".inp";
  string y = out + ".out";
  freopen(x.c_str(), "r", stdin);
  freopen(y.c_str(), "w", stdout);
}

void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

int n, k, m;
unordered_set<int> seen;

int duyet(vec<int> &k) {
  int cnt = 0;
  sort(k.begin(), k.end());
  do {
    if (k[0] == 0)
      continue;
    int p = 0;
    for (int x : k) {
      p = p * 10 + x;
    }
    if (p % m == 0) {
      if (!seen.contains(p)) {
        cnt++;
        seen.insert(p);
      }
    }
  } while (next_permutation(k.begin(), k.end()));
  return cnt;
}
void solve() {
  cin >> n >> k >> m;
  vec<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  int cnt = 0;
  vec<int> bits;
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) == k) {
      bits.push_back(i);
    }
  }
  for (int mask : bits) {
    vec<int> u;
    for (int i = 0; i < n; i++) {
      if (mask >> i & 1) {
        u.push_back(d[i]);
      }
    }
    cnt += duyet(u);
  }
  cout << cnt << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
