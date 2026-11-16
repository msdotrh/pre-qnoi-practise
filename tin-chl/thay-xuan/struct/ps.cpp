#include <bits/stdc++.h>
#include <print>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vec<pair<double, double>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  r::sort(a, [](auto x, auto y) {
    return x.first / x.second < y.first / y.second;
  });
  auto i = a[k - 1];
  int gc = gcd((int)i.first, (int)i.second);
  i.first /= gc;
  i.second /= gc;
  println("{} {}", i.first, i.second);
}
