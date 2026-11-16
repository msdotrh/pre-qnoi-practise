#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

struct hs {
  string n;
  int a, d;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<hs> a(n);
  for (auto &x : a) {
    cin >> x.n >> x.a >> x.d;
  }
  r::sort(a, [](hs a, hs b) {
    if (a.d == b.d) {
      return a.a < b.a;
    }
    return a.d < b.d;
  });
  for (auto &x : a) {
    println("{} {} {}", x.n, x.a, x.d);
  }
}
