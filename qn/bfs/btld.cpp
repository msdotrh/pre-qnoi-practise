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
int n, m;

int loang(vec<vec<int>> &a, int i, int j, int k, int x) {
  if (i < 0 || j < 0 || i >= n || j >= n) {
    // buoc ra ngoai vien
    // loang khong hop le
    return 0;
  }
  if (a[i][j] == k || a[i][j] == x) {
    return 1;
  }
  a[i][j] = k;
  int up = loang(a, i - 1, j, k, x);
  int down = loang(a, i + 1, j, k, x);
  int left = loang(a, i, j - 1, k, x);
  int right = loang(a, i, j + 1, k, x);
  if (!(up || down || left || right)) {
    return 0;
  }
  return 2;
}

void loang1(vec<int> &a, int i, int x, int k) {
  if (i < 0 || i >= m || a[i] == k || a[i] == x)
    return;
  a[i] = k;
  loang1(a, i - 1, x, k);
  loang1(a, i + 1, x, k);
}

void sub1(int n) {
  vec<int> a(m);
  for (int &x : a) {
    cin >> x;
  }
  vec<int> a1(m, 0);
  for (int i = 0; i < m; i++) {
    if (a[i] == 1 || a[i] == 3) {
      a1[i] = 1;
    }
  }
  vec<int> a2(m, 0);
  for (int i = 0; i < m; i++) {
    if (a[i] == 2 || a[i] == 3) {
      a2[i] = 2;
    }
  }
  int p = -1;
  for (int i = 0; i < m; i++) {
    if (a1[i] == 1) {
      p = i;
      break;
    }
  }
  int p2 = -1;
  for (int i = m - 1; i >= 0; i--) {
    if (a1[i] == 1) {
      p2 = i;
      break;
    }
  }
  int p3 = -1;
  for (int i = 0; i < m; i++) {
    if (a2[i] == 2) {
      p3 = i;
      break;
    }
  }
  int p4 = -1;
  for (int i = m - 1; i >= 0; i--) {
    if (a2[i] == 2) {
      p4 = i;
      break;
    }
  }
  for (int j = p; j <= p2; j++) {
    a1[j] = 1;
  }
  for (int j = p3; j <= p4; j++) {
    a2[j] = 2;
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (a1[i] == 1 && a2[i] == 2) {
      cnt++;
    }
  }
  cout << cnt << el;
}

void solve() {
  cin >> n >> m;
  if (n == 1) {
    sub1(n);
    return;
  }
  vec<vec<int>> a(n, vec<int>(m));
  for (auto &i : a) {
    for (int &x : i) {
      cin >> x;
    }
  }
  vec<vec<int>> a1(n, vec<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1 || a[i][j] == 3) {
        a1[i][j] = 1;
      }
    }
  }
  vec<vec<int>> a2(n, vec<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 2 || a[i][j] == 3) {
        a2[i][j] = 2;
      }
    }
  }
  int id = 3;
  int goodid = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a1[i][j] == 0) {
        int k = loang(a1, i, j, id, 1);
        if (k == 2) {
          goodid = id;
        }
        id++;
      }
    }
  }
  int id2 = 3;
  int goodid2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a2[i][j] == 0) {
        int k = loang(a2, i, j, id2, 2);
        if (k == 2) {
          goodid2 = id2;
        }
        id2++;
      }
    }
  }
  for (auto &i : a1) {
    for (int &z : i) {
      if (z == goodid || z == 1) {
        z = 1;
      } else {
        z = 0;
      }
    }
  }
  for (auto &i : a2) {
    for (int &z : i) {
      if (z == goodid2 || z == 2) {
        z = 2;
      } else {
        z = 0;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a1[i][j] == 1 && a2[i][j] == 2) {
        cnt++;
      }
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
