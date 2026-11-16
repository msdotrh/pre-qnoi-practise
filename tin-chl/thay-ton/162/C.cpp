// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
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

vec<vec<int>> adj;
vec<bool> visited;

void solve() {
  int n, s, t;
  cin >> n >> s >> t;
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int a = i + 1;
    int b;
    while (cin >> b) {
      if (b == 0)
        break;
      adj[a].push_back(b);
    }
  }
  stack<int> st;
  visited[s] = 1;
  st.push(s);
  vec<int> path;
  while (!st.empty()) {
    int x = st.top();
    path.push_back(x);
    st.pop();
    for (int v : adj[x]) {
      if (!visited[v]) {
        st.push(v);
        visited[v] = 1;
      }
    }
  }
  for (int x : path) {
    cout << x << " ";
  }
  cout << el;
  if (!visited[t]) {
    cout << -1 << el;
  } else {
    for (int i : path) {
      if (i == t) {
        cout << i << el;
        break;
      }
      cout << i << " ";
    }
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
