#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

struct tree {
  int a, b;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, l;
  cin >> n >> l;
  vec<tree> a(n);
  for (auto &x : a) {
    cin >> x.a >> x.b;
  }
}
