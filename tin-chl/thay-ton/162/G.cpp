// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
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

int r, c;
vec<vec<bool>> visited;
vec<string> a;

pair<int, int> dfs(int i, int j) {
  if (i < 0 || j < 0 || i > r - 1 || j > c - 1)
    return {0, 0};
  if (a[i][j] == '#') {
    return {0, 0};
  }
  if (visited[i][j]) {
    return {0, 0};
  }
  visited[i][j] = 1;
  pair<int, int> sum{0, 0};
  if (a[i][j] == 'v') {
    sum.first++;
  } else if (a[i][j] == 'o') {
    sum.second++;
  }
  vec<pair<int, int>> k{dfs(i - 1, j), dfs(i, j - 1), dfs(i + 1, j),
                        dfs(i, j + 1)};
  for (auto &i : k) {
    sum.first += i.first;
    sum.second += i.second;
  }
  return sum;
}

void solve() {
  cin >> r >> c;
  visited.assign(r, vec<bool>(c, 0));
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  int v = 0;
  int o = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (!visited[i][j]) {
        auto k = dfs(i, j);
        int mx = max(k.first, k.second);
        if (mx == k.first) {
          v += mx;
        } else {
          o += mx;
        }
      }
    }
  }
  cout << v << " " << o << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
