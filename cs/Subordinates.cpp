// #include <@msr.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<vec<int>> graph;
vec<int> memo;

int count(int x) {
  if (graph[x].size() == 0) {
    return 0;
  }
  if (memo[x] != -1)
    return memo[x];
  int cnt = graph[x].size();
  for (int v : graph[x]) {
    cnt += count(v);
  }
  return memo[x] = cnt;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  graph.resize(n + 1);
  memo.assign(n + 1, -1);
  for (int i = 0; i < n - 1; i++) {
    int k = i + 2;
    int x;
    cin >> x;
    graph[x].push_back(k);
  }
  for (int i = 1; i <= n; i++) {
    int cnt = count(i);
    cout << cnt << " ";
  }
  cout << el;
}
