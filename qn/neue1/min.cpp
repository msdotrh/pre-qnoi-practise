// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
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
int M = 1e9 + 7;

vec<int> a;
vec<int> lft, rht;

void solve() {
  cin >> n;
  a.resize(n + 2);
  lft.assign(n + 2, 0);
  rht.assign(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> st;
  a[0] = -1e18;
  st.push(0);
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] >= a[i])
      st.pop();
    lft[i] = st.top();
    st.push(i);
  }
  while (!st.empty())
    st.pop();
  a[n + 1] = -1e18;
  st.push(n + 1);
  for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()] > a[i])
      st.pop();
    rht[i] = st.top();
    st.push(i);
  }
  __int128 sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += (__int128)(i - lft[i]) * (rht[i] - i) * a[i];
    sum = (sum % M + M) % M;
  }
  cout << (int)sum % M << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
