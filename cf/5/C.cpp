// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<int> lead;
vec<int> len;

void make_set(int n) {
  lead.assign(n + 1, 0);
  len.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    lead[i] = i;
    len[i] = 1;
  }
}

int find(int v) {
  if (v == lead[v]) {
    return v;
  }
  return lead[v] = find(lead[v]);
}

void Union(int a, int b) {
  int fa = find(a);
  int fb = find(b);

  if (fa == fb)
    return;

  if (len[fa] < len[fb]) {
    swap(fa, fb);
  }
  lead[fb] = fa;
  len[fa] += len[fb];
}

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  if (ranges::is_sorted(a)) {
    cout << "YES" << el;
    return;
  }
  make_set(n);
  vec<bool> visited;
  visited.assign(n + 1, 0);
  vec<int> d;
  if (x == y) {
    d = {x};
  } else {
    d = {x, y};
  }
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    for (int _ = 0; _ < d.size(); _++) {
      for (int j = i; j < n; j += d[_]) {
        Union(a[i], a[j]);
        visited[j] = 1;
      }
    }
  }
  // check
  for (int i = 0; i < n; i++) {
    int x = a[i];
    if (find(x) != find(i + 1)) {
      cout << "NO" << el;
      return;
    }
  }
  cout << "YES" << el;
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
