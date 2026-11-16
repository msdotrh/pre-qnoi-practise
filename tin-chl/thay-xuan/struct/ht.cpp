#include <bits/stdc++.h>
#include <iterator>
#include <print>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

struct phanso {
  int a, b;
  long double thapphan;
  void rutgon() {
    int gc = gcd(a, b);
    this->a /= gc;
    this->b /= gc;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  // gen
  auto comp = [](phanso a, phanso b) { return a.thapphan < b.thapphan; };
  set<phanso, decltype(comp)> st;
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (j == 0)
        continue;
      phanso a{i, j, (long double)i / (long double)j};
      a.rutgon();
      st.insert(a);
    }
  }
  auto it = next(st.begin(), k - 1);
  for (auto i : st) {
    println("{} / {} = {}", i.a, i.b, i.thapphan);
  }
  println("{}\n{} {}", st.size(), it->a, it->b);
}
