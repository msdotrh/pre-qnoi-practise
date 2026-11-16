// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <queue>
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

void solve() {
  int r, c;
  cin >> r >> c;
  vec<string> a(r);
  for (string &x : a) {
    cin >> x;
  }
  vec<vec<int>> visited(r + 1, vec<int>(c + 1, 0));
  vec<vec<int>> dist(r + 1, vec<int>(c + 1, -1));
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = 1;
  dist[0][0] = 0;
  int dx[]{1, -1, 0, 0};
  int dy[]{0, 0, -1, 1};
  while (!q.empty()) {
    pair x = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> neue{x.first + dx[i], x.second + dy[i]};
      if (neue.first < 0 || neue.second < 0 || neue.first >= r ||
          neue.second >= c || a[neue.first][neue.second] == '#' ||
          visited[neue.first][neue.second]) {
        continue;
      }
      visited[neue.first][neue.second] = 1;
      dist[neue.first][neue.second] = dist[x.first][x.second] + 1;
      q.push(neue);
    }
  }
  cout << dist[r - 1][c - 1] << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
