#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

struct pos {
  int y, x;

  bool operator==(const pos &other) const {
    return y == other.y && x == other.x;
  }
};

vec<string> a;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  a.resize(n);
  for (auto &i : a) {
    cin >> i;
  }
  pos apos, bpos;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'A') {
        apos = pos{i, j};
      }
      if (a[i][j] == 'B') {
        bpos = pos{i, j};
      }
    }
  }
  // bfs
  vec<vec<bool>> visited(n, vec<bool>(m, 0));
  vec<vec<pos>> prev(n, vec<pos>(m, {0, 0}));
  queue<pos> q;
  q.push(apos);
  visited[apos.y][apos.x] = 1;
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, -1, 0, 1};
  while (!q.empty()) {
    pos old = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pos neue = {old.y + dy[i], old.x + dx[i]};
      if (neue.x < 0 || neue.y < 0 || neue.x >= m || neue.y >= n) {
        continue;
      }
      if (visited[neue.y][neue.x]) {
        continue;
      }
      if (a[neue.y][neue.x] == '#') {
        continue;
      }
      visited[neue.y][neue.x] = 1;
      prev[neue.y][neue.x] = old;
      q.push(neue);
    }
  }

  if (visited[bpos.y][bpos.x]) {
    cout << "YES" << el;
    string path;
    pos cur = bpos;
    while (!(cur == apos)) {
      pos p = prev[cur.y][cur.x];
      if (p.y == cur.y - 1) {
        path += 'D';
      } else if (p.y == cur.y + 1) {
        path += 'U';
      } else if (p.x == cur.x - 1) {
        path += 'R';
      } else if (p.x == cur.x + 1) {
        path += 'L';
      }
      cur = p;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << el;
    cout << path << el;
  } else {
    cout << "NO" << el;
  }
}
