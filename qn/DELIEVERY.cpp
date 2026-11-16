// #include <@msr.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
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

int n, m;
vec<int> a;

void solve() {
  cin >> n >> m;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  r::sort(a, greater<int>{});
  queue<int> q;
  for (int x : a) {
    q.push(x);
  }
  int cost = 0;
  while (!q.empty()) {
    // lay m phan tu
    int sz = q.size();
    int cur = 0;
    for (int i = 0; i < min(m, sz); i++) {
      int x = q.front();
      q.pop();
      cost += abs(cur - x);
      cur = x;
    }
    cost += abs(cur - 0);
  }
  cout << cost << el;
}

signed main() {
  io();
  open("DELIVERY", "DELIVERY");
  // cin >> t;
  while (t--) {
    solve();
  }
}
