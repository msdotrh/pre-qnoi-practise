#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m, n;
  cin >> m >> n;
  int x, y, u, v;
  cin >> x >> y >> u >> v;
  vec<vec<int>> a(m + 1, vec<int>(n + 1, 1));
  vec<vec<bool>> visited(m + 1, vec<bool>(n + 1, 0));
  vec<vec<int>> pre(m + 1, vec<int>(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = 1;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> neue{curr.first + dy[i], curr.second + dx[i]};
      if ((neue.first > m || neue.first < 1) ||
          (neue.second > n || neue.second < 1)) {
        continue;
      }
      if (visited[neue.first][neue.second]) {
        continue;
      }
      if (a[neue.first][neue.second] == 1) {
        continue;
      }
      q.push(neue);
      visited[neue.first][neue.second] = 1;
      pre[neue.first][neue.second] = pre[curr.first][curr.second] + 1;
    }
  }
  if (!visited[u][v]) {
    cout << -1 << el;
  } else {
    cout << pre[u][v] << el;
  }
}
