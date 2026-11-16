// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
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

int n, m;
string s;

int cal(string &x) {
  map<int, int> p;
  for (int i = 0; i < x.size(); i++) {
    p[x[i]] = i;
  }
  int c = 0;
  for (int i = 1; i < n; i++) {
    c += abs(p[s[i]] - p[s[i - 1]]);
  }
  return c;
}

void solve() {
  cin >> n >> m;
  cin >> s;
  string key;
  for (int i = 0; i < m; i++) {
    key.push_back(i + 'a');
  }
  int mn = MAX;
  do {
    mn = min(mn, cal(key));
  } while (next_permutation(key.begin(), key.end()));
  cout << mn << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
