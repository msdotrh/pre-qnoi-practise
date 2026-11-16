#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<vec<pair<int, int>>> graph;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
  }
}
