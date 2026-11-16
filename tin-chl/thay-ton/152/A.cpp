#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

int n;
vec<int> a(n);
vec<int> b;

bool check(vec<int> &a) {
  for (int i = 0; i < n - 1; i++) {
    int j = i + 1;
    if (a[i] == a[j]) {
      return false;
    }
  }
  return true;
}

void f(vec<int> &x) {
  for (int i = 0; i < x.size() - 1; i++) {
    int j = i + 1;
    if (x[i] == x[j]) {
      b.push_back(x[i] + 1);
      i++;
    } else {
      b.push_back(x[i]);
      i++;
      b.push_back(x[j]);
    }
  }

  for (int x : b) {
    cout << x << " ";
  }
  cout << el;
  a = b;
  b.clear();
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int &x : a) {
    cin >> x;
  }
  while (!check(a)) {
    f(a);
  }
  cout << b.size();
}
