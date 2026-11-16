// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <set>
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
string s;

void sub1() {
  string res;
  string res2;
  int cnt = 1;
  int bit = 0;
  for (int i = 0; i < n; i++) {
    if (cnt > k) {
      cnt = 0;
      // dao bit
      bit = !bit;
    }
    res.push_back(bit + '0');
    res2.push_back(!bit + '0');
    cnt++;
  }
  int cs1 = 0, cs2 = 0;
  for (int i = 0; i < n; i++) {
    if (res[i] != s[i]) {
      cs1++;
    }
    if (res2[i] != s[i]) {
      cs2++;
    }
  }
  if (cs1 < cs2) {
    cout << cs1 << el << res << el;
  } else {
    cout << cs2 << el << res2 << el;
  }
}

void sub2() {
  string str1;
  string str2;
  int bit = 0;
  for (int i = 0; i < n; i++) {
    str1.push_back(bit + '0');
    bit = !bit;
    str2.push_back(bit + '0');
  }
  int cs1 = 0, cs2 = 0;
  for (int i = 0; i < n; i++) {
    if (str1[i] != s[i]) {
      cs1++;
    }
    if (str2[i] != s[i]) {
      cs2++;
    }
  }
  if (cs1 < cs2) {
    cout << cs1 << el << str1 << el;
  } else {
    cout << cs2 << el << str2 << el;
  }
}

void subdangcap() {
  int tg = 1;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    int c = s[i];
    if (c == s[i - 1]) {
      tg++;
    } else {
      tg = 1;
    }
    if (tg > k) {
      cnt++;
      s[i] = (s[i] == '0' ? '1' : '0');
      tg = 1;
    }
  }
  cout << cnt << el << s << el;
}

void solve() {
  cin >> n >> k;
  cin >> s;
  subdangcap();
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
