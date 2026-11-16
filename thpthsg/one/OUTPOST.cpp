// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
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

int n, k;
vec<int> a;
vec<vec<int>> adj;

void solve() {
  cin >> n >> k;
  adj.resize(n + 1);
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (k == 1) {
    cout << *max_element(a.begin(), a.end());
  }
  cout << el;
}

signed main() {
  io();
  open("OUTPOST", "OUTPOST");
  // cin >> t;
  while (t--) {
    solve();
  }
}
