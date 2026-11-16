// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <ranges>
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

map<char, int> six = {{'s', 1}, {'i', 1}, {'x', 1}};

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  map<char, int> mp;
  for (char c : s) {
    mp[c]++;
  }
  map<char, int> mp2;
  for (char c : t) {
    mp[c]--;
  }
  auto filtered =
      mp | std::views::filter([](const auto &x) { return x.second != 0; });
  if (r::equal(filtered.begin(), filtered.end(), six.begin(), six.end())) {
    cout << "YES" << el;
  } else {
    cout << "NO" << el;
  }
}

signed main() {
  io();
  cin >> t;
  while (t--) {
    solve();
  }
}
