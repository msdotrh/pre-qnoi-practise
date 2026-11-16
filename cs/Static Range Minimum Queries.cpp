// #include <@msr.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

vec<int> t;
vec<int> a;

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

int get(int node, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) {
    return 1e17;
  }

  if (l >= ql && r <= qr) {
    return t[node];
  }

  int m = (l + r) / 2;
  int left = get(node * 2, l, m, ql, qr);
  int right = get(node * 2 + 1, m + 1, r, ql, qr);

  return min(left, right);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  t.assign(4 * n + 1, 0);
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  build(1, 0, n - 1);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << get(1, 0, n - 1, a - 1, b - 1) << el;
  }
}
