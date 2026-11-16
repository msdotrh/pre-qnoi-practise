// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <queue>
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

void solve() {
  int n, k;
  cin >> n >> k;
  priority_queue<int, vec<int>> pq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pq.push(x);
  }
  int sum = 0;
  while (k--) {
    int x = pq.top();
    if (x == 0)
      break;
    pq.pop();
    x /= 2;
    pq.push(x);
  }
  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }
  cout << sum << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
