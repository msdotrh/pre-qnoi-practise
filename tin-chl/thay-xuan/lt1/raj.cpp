// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <print>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T>;
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

int input() {
  int h, m;
  char racruoi;
  cin >> h >> racruoi >> m;
  return h * 60 + m;
}

int solve() {
  int n, r, s;
  cin >> n;
  int close = input(), wake = input(), open = input();
  cin >> r >> s;
  vec<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x = input();
    int y = input();
    a.push_back({x, y});
  }
  auto check = [&](pair<int, int> x, int done, int start) {
    // println("{} va {}", pair{start, done}, x);
    // [start, done], x ko giao nhau
    return done < x.first || start > x.second;
  };
  for (int start = wake; start <= close; start++) {
    int go = max(start + r, open);
    int done = go + r + s;
    if (done >= close) {
      break;
    }
    for (int i = 0; i < n; i++) {
      if (check(a[i], done, start)) {
        return i;
      }
    }
  }
  return -1;
}

signed main() {
  io();
  cin >> t;
  int cnt = 1;
  while (t--) {
    int tg = solve();
    println("Case {}: {}", cnt, (tg == -1 ? -1 : tg + 1));
    cnt++;
  }
}
