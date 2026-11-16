#include <bits/stdc++.h>
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
  unsigned a;
  cin >> a;
  unsigned b = a;
  unsigned c = (1 << (__lg(a) + 1)) - a - 1;
  cout << b << " " << c << el;
}
