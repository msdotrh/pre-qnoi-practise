// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <print>
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

void solve() {
  int n, k;
  cin >> n >> k;
  vec<pair<int, int>> inp;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    inp.push_back({a, b});
  }
  r::sort(inp, [](auto x, auto y) { return x.second < y.second; });
  vec<bool> visited(n, 0);
  println("{}", inp);
  int ans = 0;
  int curr = 0;
  multiset<int> ms;
  for (int i = 0; i < n; i++) {
    auto x = inp[i];
    if (curr > x.first) {
      continue;
    }
    curr = x.second;
    ans++;
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
