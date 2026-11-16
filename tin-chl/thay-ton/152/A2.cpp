#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void sub2(int n) {
  cout << (n % 2) + 2;
  cout << el;
}

bool check(vec<int> &a) {
  for (int i = 0; i < a.size() - 1; i++) {
    int j = i + 1;
    if (a[i] == a[j]) {
      return false;
    }
  }
  return true;
}

void sub67(vec<int> &a) {
  while (!check(a)) {
    for (int j = 0; j < a.size() - 1; j++) {
      int i = j + 1;
      if (a[i] == a[j]) {
        a[i]++;
        a.erase(a.begin() + j);
        break;
      }
    }
  }
  cout << a.size();
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  bool ok = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      ok = 0;
    }
  }
  if (ok) {
    sub2(n);
  } else {
    sub67(a);
  }
}
