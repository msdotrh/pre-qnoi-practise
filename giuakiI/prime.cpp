#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n, k;

int lcm(int x, int y) {
  int gc = __gcd(x, y);
  return x * y / gc;
}

void sub2() {
  int a, b;
  cin >> a >> b;
  int pa = k / a;
  int pb = k / b;
  int pab = k / lcm(a, b);
  int res = pa + pb - pab;
  cout << res << el;
}

void sub3() {
  int a, b, c;
  cin >> a >> b >> c;
  int pa = k / a;
  int pb = k / b;
  int pc = k / c;
  int pab = k / lcm(a, b);
  int pac = k / lcm(a, c);
  int pbc = k / lcm(b, c);
  int pabc = k / lcm(lcm(a, b), c);
  int res = pa + pb + pc - pab - pac - pbc + pabc;
  cout << res << el;
}

void sub1() {
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vec<bool> visited(k + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j += a[i]) {
      visited[j] = 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i <= k; i++) {
    if (visited[i]) {
      cnt++;
    }
  }
  cout << cnt << el;
}

void sub4() {
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("prime.inp", "r", stdin);
  freopen("prime.out", "w", stdout);
  cin >> n >> k;
  if (n == 2) {
    sub2();
  } else if (n == 3) {
    sub3();
  } else {
    sub4();
  }
}
