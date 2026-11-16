#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int n, w1, w2;

struct mv {
  int m, v;
};

vec<mv> a;
int knapsack(int ind, int w1, int w2) {
  if (ind < 0) {
    return 0;
  }
  if (w1 == 0 || w2 == 0) {
    // dc cua no
    return a[ind].v;
  }
  if (w1 < 0 || w2 < 0) {
    return 0;
  }
  int takew1 = a[ind].v + knapsack(ind - 1, w1 - a[ind].m, w2);
  int takew2 = a[ind].v + knapsack(ind - 1, w1, w2 - a[ind].m);
  int notake = knapsack(ind - 1, w1, w2);
  return max({takew2, takew1, notake});
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> w1 >> w2;
  a.resize(n);
  for (auto &x : a) {
    cin >> x.m >> x.v;
  }
  cout << knapsack(n - 1, w1, w2);
  cout << el;
}
