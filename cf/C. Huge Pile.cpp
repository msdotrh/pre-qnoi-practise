// #include <@msr.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  int a, b;
  cin >> a >> b;
  if (b > a) {
    cout << -1 << el;
    return;
  }
  unordered_map<int, int> visited;
  queue<int> q;
  q.push(a);
  visited[a] = 0;
  while (!q.empty()) {
    int x = q.front();
    if (x == b) {
      cout << visited[b] << el;
      return;
    }
    q.pop();
    int k = x / 2;
    if (!visited.contains(k) && k >= b) {
      q.push(k);
      visited[k] = visited[x] + 1;
    }
    if (!visited.contains(x - k) && x - k >= b) {
      q.push(x - k);
      visited[x - k] = visited[x] + 1;
    }
  }
  if (visited.contains(b)) {
    cout << visited[b] << el;
    return;
  }
  cout << -1 << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
