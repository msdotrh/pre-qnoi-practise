#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

struct tree {
  vec<int> t;
  vec<int> a;

  tree(vec<int> &a_out) {
    a = std::move(a_out);
    t.resize(4 * (a.size() + 1));
    build(1, 0, a.size() - 1);
  }

  void build(int node, int l, int r) {
    if (l == r) {
      t[node] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(node * 2, l, m);
    build(node * 2 + 1, m + 1, r);

    t[node] = min(t[node * 2], t[node * 2 + 1]);
  }

  int get(int node, int l, int r, int q_l, int q_r) {
    // case 1: out of range
    if (q_r < l || q_l > r) {
      return INT_MAX;
    }
    // case 2: fit in range
    if (q_l <= l && r <= q_r) {
      return t[node];
    }
    // case 3: partial
    int m = (l + r) / 2;
    int ql = get(node * 2, l, m, q_l, q_r);
    int qr = get(node * 2 + 1, m + 1, r, q_l, q_r);
    return min(ql, qr);
  }

  void update(int node, int l, int r, int p, int v) {
    if (p < l || p > r) {
      return;
    }
    if (l == r) {
      t[node] = v;
      a[p] = v;
      return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, p, v);
    update(node * 2 + 1, m + 1, r, p, v);
    t[node] = min(t[node * 2], t[node * 2 + 1]);
  }

  void update(int p, int v) { update(1, 0, a.size() - 1, p, v); }
  int get(int l, int r) { return get(1, 0, a.size() - 1, l, r); }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  tree sg(a);
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
