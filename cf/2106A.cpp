// #include <@msr.h>
#include <bitset>
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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k = bitset<10>(s).to_ullong();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int f = k ^ (1 << i);
    sum += __builtin_popcount(f);
  }
  cout << sum << el;
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
