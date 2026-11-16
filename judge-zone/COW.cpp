#include <algorithm>
#include <bits/stdc++.h>
#include <unistd.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

struct k {
  char c;
  int f;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vec<k> p;
  char last{s[0]};
  int cnt{1};
  for (int i = 1; i < n; i++) {
    if (last == s[i]) {
      cnt++;
    } else {
      p.push_back({last, cnt});
      cnt = 1;
    }
    last = s[i];
  }
  p.push_back({last, cnt});
  vec<int> c;
  vec<int> o;
  vec<int> w;
  for (int i = 0; i < p.size(); i++) {
    if (p[i].c == 'C') {
      c.push_back(i);
    } else if (p[i].c == 'O') {
      o.push_back(i);
    } else {
      w.push_back(i);
    }
  }
  int cc{0};
  for (int i = 0; i < c.size(); i++) {
    auto it = ranges::upper_bound(o, c[i]);
    if (it == o.end()) {
      break;
    }
    for (int j = it - o.begin(); j < o.size(); j++) {
      auto itt = ranges::upper_bound(w, o[j]);
      if (itt == w.end()) {
        break;
      }
      for (int k = itt - w.begin(); k < w.size(); k++) {
        cc += p[c[i]].f * p[o[j]].f * p[w[k]].f;
      }
    }
  }
  cout << cc << el;
}
