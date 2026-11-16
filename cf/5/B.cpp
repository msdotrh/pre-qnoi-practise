// #include <@msr.h>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void solve() {
  int m, n;
  cin >> n >> m;
  if (m > n) {
    cout << "NO" << el;
    return;
  }
  unordered_set<int> visited;
  queue<int> q;
  q.push(n);
  visited.insert(n);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x % 3 != 0) {
      continue;
    }
    int k = x / 3;
    // push k, k*2;
    if (!visited.contains(k)) {
      q.push(k);
      visited.insert(k);
    }
    if (!visited.contains(k * 2)) {
      q.push(k * 2);
      visited.insert(k * 2);
    }
  }
  cout << (visited.contains(m) ? "YES" : "NO") << el;
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
