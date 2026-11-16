// #include <@msr.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
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

vec<pair<int, int>> circles;
vec<vec<int>> graph;

void solve() {
  int l, w, n;
  cin >> l >> w >> n;
  graph.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    circles[i] = {x, y};
  }
  // check lien thong
  for (int i = 0; i < n; i++) {
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double k = sqrt(1.0 * pow(abs(circles[i].first - circles[j].first), 2.0) +
                      pow(abs(circles[i].second - circles[j].second), 2.0));
      if (k <= 200) {
        // trung
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
