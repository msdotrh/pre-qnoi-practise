#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n, k;
vec<int> a;
vec<int> b;

void sub1() {
  int mxa = *max_element(a.begin(), a.end());
  int mxb = *max_element(b.begin(), b.end());
  int mna = *min_element(a.begin(), a.end());
  int mnb = *min_element(b.begin(), b.end());
  int mx = max({mxa * mxb, mna * mnb, mxa * mnb, mna * mxb});
  cout << mx << el;
}

void sub2() {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vec<int> resv;
  for (int i = 0; i < n; i++) {
    int x = a[i] * b[i];
    resv.push_back(x);
  }
  sort(resv.begin(), resv.end(), greater<int>());
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += resv[i];
  }
  cout << sum << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("kseq.inp", "r", stdin);
  freopen("kseq.out", "w", stdout);
  cin >> n >> k;
  a.resize(n);
  b.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  for (int &x : b) {
    cin >> x;
  }
  if (k == 1) {
    sub1();
  } else if (k == 2) {
    sub2();
  } else {
    sub2();
  }
}
