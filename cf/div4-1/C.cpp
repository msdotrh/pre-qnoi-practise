// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <functional>
#include <iostream>
#include <print>
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

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  deque<int> dq;
  sort(a.begin(), a.end(), greater<int>());
  int seen = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && a[i] == a[i - 1]) {
      seen++;
    } else {
      seen = 1;
    }
    if (seen == 1) {
      dq.push_front(a[i]);
    } else {
      dq.push_back(a[i]);
    }
  }
  int cnt = 0;
  vec<int> k(dq.begin(), dq.end());
  vec<bool> visited(n + 1, 0);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int curr = k[i];
    if (mx < curr) {
      mx = curr;
      if (!visited[i]) {
        cnt++;
        visited[i] = 1;
      }
    }
  }
  mx = 0;
  for (int i = n - 1; i >= 0; i--) {
    int curr = k[i];
    if (mx < curr) {
      mx = curr;
      if (!visited[i]) {
        cnt++;
        visited[i] = 1;
      }
    }
  }
  cout << cnt << el;
  for (int i = 0; i < n; i++) {
    cout << k[i] << " ";
  }
  cout << el;
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
