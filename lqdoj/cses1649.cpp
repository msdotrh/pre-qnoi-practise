#include <bits/stdc++.h>
#include <print>
using namespace std;
#define int long long

vector<int> a;
int n, q;

struct Tree {
  vector<int> tree;

  Tree() {
    tree.resize(4 * n + 1);
    build(1, 0, n - 1);
  }

  void build(int node, int l, int r) {
    if (l == r) {
      tree[node] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(node * 2, l, m);
    build(node * 2 + 1, m + 1, r);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }

  int get(int node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
      return 1e18;
    }
    if (ql <= l && qr >= r) {
      return tree[node];
    }
    int m = (l + r) / 2;
    int left = get(node * 2, l, m, ql, qr);
    int right = get(node * 2 + 1, m + 1, r, ql, qr);
    return min(left, right);
  }

  void update(int node, int l, int r, int p, int x) {
    if (p < l || p > r) {
      return;
    }
    if (l == r) {
      tree[node] = x;
      a[p] = x;
      return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, p, x);
    update(node * 2 + 1, m + 1, r, p, x);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }

  int get(int l, int r) { return get(1, 0, n - 1, l, r); }
  void update(int p, int x) { return update(1, 0, n - 1, p, x); }
};

signed main() {
  cin >> n >> q;
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  Tree sg;
  println("{}", sg.tree);
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    if (t == 1) {
      sg.update(a, b);
    } else {
      cout << sg.get(a, b) << '\n';
    }
  }
}
