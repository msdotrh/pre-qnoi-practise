#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

#ifdef DEBUG
#define dbg(fmt, ...)                                                          \
  std::println(stderr, "\033[91m" fmt "\033[0m", ##__VA_ARGS__)
#else
#define dbg(...)
#endif

struct k {
  char c;
  int f;
};

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vec<k> p;
  int cnt{1};
  char last{s[0]};
  for (int i{1}; i < n; i++) {
    if (last == s[i]) {
      cnt++;
    } else {
      p.push_back({last, cnt});
      cnt = 1;
    }
    last = s[i];
  }
  p.push_back({last, cnt});
  int x{0}, y{0};
  // x : 0
  // y : 1
  for (auto i : p) {
    if (i.c == '0')
      x += i.f - 1;
    if (i.c == '1')
      y += i.f - 1;
  }

  int dif{abs(x - y)};
  if (dif <= 1) {
    cout << x + y << el;
    return;
  }

  char need = (x > y ? '1' : '0');

  if (dif == 2) {
    if (s.front() == need || s.back() == need) {
      cout << x + y + 1 << el;
    } else {
      cout << -1 << el;
    }
    return;
  }

  if (dif == 3) {
    if (s.front() == need && s.back() == need) {
      cout << x + y + 2 << el;
    } else {
      cout << -1 << el;
    }
    return;
  }

  cout << -1 << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
