// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T>;
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

int MAX = 1e18;
int MIN = -MAX;

int n, s, t;

vec<int> a;
vec<int> visited;
vec<int> dist;

void solve() {
  cin >> n >> s >> t;
  s--, t--;
  a.assign(n, 0);
  for (int& x : a) {
    cin >> x;
  }
  visited.assign(n + 1, 0);
  dist.assign(n + 1, -1);
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  dist[s] = 0;
  while (!q.empty()) {
    int x = q.front();
    // cout << x << el;
    if (x == t) break;
    q.pop();
    int left = x - a[x];
    int right = x + a[x];
    if (left >= 0 && !visited[left]) {
      dist[left] = dist[x] + 1;
      visited[left] = 1;
      q.push(left);
    }
    if (right < n && !visited[right]) {
      dist[right] = dist[x] + 1;
      visited[right] = 1;
      q.push(right);
    }
  }
  cout << dist[t] << el;
}

signed main() {
  io();
  // cin >> t;
  solve();
}
