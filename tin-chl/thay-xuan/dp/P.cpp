#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<vec<bool>> visited;
vec<int> c;
int n, m, b;

void mark(pair<int, int> p) {
  if (p.first < 0 || p.second < 0 || p.first >= n + 1 || p.second >= m + 1)
    return;
  if (visited[p.first][p.second])
    return;
  visited[p.first][p.second] = 1;
  int g = p.first;
  mark({p.first + 1, p.second + c[g]});
  mark({p.first + 1, p.second - c[g]});
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> b;
  visited.assign(n + 1, vec<bool>(m + 1, 0));
  c.resize(n + 5);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  pair<int, int> init = {0, b};
  mark(init);
  int cnt = 0;
  for (bool x : visited[m]) {
    cnt += x;
  }
  if (cnt == 0) {
    cnt--;
  }
  cout << cnt << el;
}
