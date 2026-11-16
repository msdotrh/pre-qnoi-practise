// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
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
int n;

vec<int> a;
vec<int> b;
vec<int> k;

vec<unordered_set<int>> kka;
vec<unordered_set<int>> kkb;

void pre() {
  k.assign(n, 0);
  kka.resize(n);
  kkb.resize(n);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int y = b[i];
    if (i == 0) {
      kka[i].insert(x);
      kkb[i].insert(y);
    } else {
      kka[i] = kka[i - 1];
      kkb[i] = kkb[i - 1];
      kka[i].insert(x);
      kkb[i].insert(y);
    }
  }
}

void query() {
  int x, y;
  cin >> x >> y;
  x--, y--;
  if (kka[x] == kkb[y]) {
    cout << "Yes" << el;
  } else {
    cout << "No" << el;
  }
}

void solve() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  for (int &x : b) {
    cin >> x;
  }
  pre();
  int q;
  cin >> q;
  while (q--) {
    query();
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
