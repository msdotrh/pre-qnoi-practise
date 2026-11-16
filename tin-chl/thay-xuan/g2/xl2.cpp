// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
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

struct s {
  int d, w;
};

int n;
vec<s> a;

void solve() {
  cin >> n;
  a.resize(n);
  for (auto &y : a) {
    cin >> y.d >> y.w;
  }
  r::sort(a, [](s a, s b) { return a.w > b.w; });
  /*
  for (int i = 0; i < n; i++) {
    cout << a[i].d << " : " << a[i].w << el;
  }
  */
  map<int, int> mp;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int k = a[i].d;
    for (int j = k; j >= 1; j--) {
      if (!mp.contains(j)) {
        mp[j] = a[i].w;
        break;
      }
    }
  }
  for (auto i : mp) {
    sum += i.second;
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
