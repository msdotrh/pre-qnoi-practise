// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
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
  int g, n;
  cin >> g >> n;
  string w, s;
  cin >> w >> s;
  unordered_map<char, int> mp;
  for (char c : w) {
    mp[c]++;
  }
  // init
  int cnt = 0;
  unordered_map<char, int> mp2;
  for (int i = 0; i < g; i++) {
    char c = s[i];
    mp2[c]++;
  }
  if (mp2 == mp) {
    cnt++;
  }
  for (int i = g; i < n; i++) {
    char c = s[i];
    mp2[c]++;
    mp2[s[i - g]]--;
    if (mp2[s[i - g]] == 0) {
      mp2.erase(mp2.find(s[i - g]));
    }
    if (mp2 == mp) {
      cnt++;
    }
  }
  cout << cnt << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
