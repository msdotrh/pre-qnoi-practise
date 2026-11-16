#include <algorithm>
#include <bits/stdc++.h>
#include <print>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

struct sell {
  int a, b;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vec<sell> a(m);
  for (auto &x : a) {
    cin >> x.a >> x.b;
  }
  r::sort(a, [](sell x, sell y) { return x.a < y.a; });
  int sum = 0;
  for (auto i : a) {
    // mua
    if (n == 0) {
      break;
    }
    if (n >= i.b) {
      // mua het
      n -= i.b;
      sum += i.b * i.a;
    } else {
      // mua het n
      sum += n * i.a;
      n = 0;
    }
  }
  println("{}", sum);
}
