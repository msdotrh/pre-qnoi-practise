// #include <@msr.h>
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

struct k {
  int a, b;
};

void solve() {
  int n;
  cin >> n;
  vec<k> p(n);
  for (auto &i : p) {
    cin >> i.a >> i.b;
  }
  int kq = 0;
  for (int i = n - 1; i >= 0; i--) {
    int k = p[i].a + kq;
    int a = k % p[i].b;
    if (a > 0) {
      int thieu = p[i].b - a;
      kq += thieu;
    }
  }
  cout << kq << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
