// #include <@msr.h>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
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

bool comp(string &s, string &y) {
  unordered_set<char> st(s.begin(), s.end());
  bool ok = 0;
  for (char c : y) {
    if (st.contains(c)) {
      ok = 1;
      break;
    }
  }
  return ok;
}

void solve() {
  int n;
  cin >> n;
  vec<string> a(n);
  int cnt = 0;
  for (string &s : a) {
    cin >> s;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (comp(a[i], a[j])) {
        cnt++;
      }
    }
  }
  cout << cnt << el;
}

int chng(string &x) {
  bitset<10> bs;
  for (char c : x) {
    bs[c - '0'] = 1;
  }
  int ans = bs.to_ullong();
  return ans;
}

void sub2() {
  int n;
  cin >> n;
  vec<string> a(n);
  a.resize(n);
  for (string &s : a) {
    cin >> s;
  }
  unordered_map<int, int> mp;
  for (string &x : a) {
    int tg = chng(x);
    mp[tg]++;
  }
  for (auto i : mp) {
    cout << i.first << " " << i.second << el;
  }
  for (auto i : mp) {
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    sub2();
  }
}
