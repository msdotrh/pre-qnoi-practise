// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <print>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
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

int n;
vec<int> a;

void sub1() {
  set<vec<int>> seen;
  for (int mask = 1; mask < (1 << n); mask++) {
    vec<int> k;
    for (int i = 0; i < n; i++) {
      if (mask >> i & 1) {
        k.push_back(a[i]);
      }
    }
    seen.insert(k);
  }
  cout << seen.size() << el;
}

const int M = 1e9 + 7;
vec<int> memo;

int dp(int i) {
  int &mem = memo[i];
  if (mem != -1)
    return mem;
  int cnt = 1;
  unordered_set<int> st;
  for (int j = i + 1; j < n; j++) {
    if (!st.contains(a[j])) {
      st.insert(a[j]);
      cnt += dp(j);
      if (cnt >= M) {
        cnt -= M;
      }
    }
  }
  return mem = cnt;
}

void sub2() {
  memo.assign(n + 1, -1);
  int kq = 0;
  unordered_set<int> st;
  for (int i = 0; i < n; i++) {
    if (!st.contains(a[i])) {
      st.insert(a[i]);
      kq += dp(i);
      if (kq >= M)
        kq -= M;
    }
  }
  cout << kq << el;
}

void solve() {
  cin >> n;
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  if (n <= 20) {
    sub1();
  } else {
    sub2();
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
