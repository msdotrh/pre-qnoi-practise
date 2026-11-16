// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <set>
#include <string>
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
set<int> st;
int visited[100005][105];

void dp(int sum, int i) {
  if (visited[sum][i]) {
    return;
  }
  if (sum > 0) {
    st.insert(sum);
  }
  if (i == n) {
    visited[sum][i] = 1;
    return;
  }

  // skip
  dp(sum, i + 1);
  // take
  dp(sum + a[i], i + 1);

  visited[sum][i] = 1;
}

void solve() {
  cin >> n;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  auto osum = r::fold_left_first(a, plus<int>());
  int sum = osum.value();
  dp(0, 0);
  cout << st.size() << el;
  for (int x : st) {
    cout << x << " ";
  }
  cout << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
