#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<int> p;
void back(int x, int ind) {
  if (x < 0)
    return;
  if (x == 0) {
    for (int i : p) {
      cout << i << " ";
    }
    cout << el;
    return;
  }
  if (ind <= 0)
    return;
  p.push_back(ind);
  // take
  back(x - ind, ind - 1);
  if (!p.empty())
    p.pop_back();
  // no take
  back(x, ind - 1);
  if (!p.empty())
    p.pop_back();
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  back(n, n);
}
