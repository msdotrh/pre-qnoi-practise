// #include <@msr.h>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int q;

struct Sg {
  int n;
  vec<int> a, t;

  Sg() {
    cin >> n >> q;
    a.resize(n);
    t.resize(4 * n + 1);
    for (int &x : a)
      cin >> x;
    build(1, 0, n - 1);
  }

  void build(int node, int l, int r) {
    if (l == r) {
      t[node] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(node * 2, l, m);
    build(node * 2 + 1, m + 1, r);
    t[node] = t[node * 2] + t[node * 2 + 1];
  }

  int get(int node, int l, int r, int ql, int qr) {
    // out of range
    if (l > qr || ql > r) {
      return 0;
    }
    // in range
    if (l >= ql && r <= qr) {
      return t[node];
    }
    int m = (l + r) / 2;
    int left = get(node * 2, l, m, ql, qr);
    int right = get(node * 2 + 1, m + 1, r, ql, qr);
    return left + right;
  }

  void update(int node, int l, int r, int p, int x) {
    // out of range
    if (p > r || p < l) {
      return;
    }
    if (r == l) {
      // update
      t[node] = x;
      a[p] = x;
      return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, p, x);
    update(node * 2 + 1, m + 1, r, p, x);
    t[node] = t[node * 2] + t[node * 2 + 1];
  }

  int get(int l, int r) { return get(1, 0, n - 1, l, r); }
  void update(int p, int x) { return update(1, 0, n - 1, p, x); }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Sg sg;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      sg.update(a - 1, b);
    } else {
      cout << sg.get(a - 1, b - 1) << el;
    }
  }
}
