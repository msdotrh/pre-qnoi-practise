#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

struct benhnhan {
  int id, t, d, p;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<benhnhan> a(n);
  for (auto &x : a) {
    cin >> x.id >> x.t >> x.d >> x.p;
  }
  priority_queue<benhnhan, vec<benhnhan>, decltype([](benhnhan x, benhnhan y) {
                   if (x.p == y.p) {
                     if (x.t == y.t) {
                       return x.id > y.id;
                     }
                     return x.t > y.t;
                   }
                   return x.p < y.p;
                 })>
      pq;

  priority_queue<benhnhan, vec<benhnhan>,
                 decltype([](benhnhan x, benhnhan y) { return x.t > y.t; })>
      pqt;

  for (benhnhan &x : a) {
    pqt.push(x);
  }

  int cnt = 0;
  int t = 0;
  int ranh = 0;
  vec<int> id;
  while (cnt != n) {
    while (!pqt.empty() && pqt.top().t <= t) {
      auto x = pqt.top();
      pqt.pop();
      pq.push(x);
    }
    if (!pq.empty()) {
      auto y = pq.top();
      id.push_back(y.id);
      pq.pop();
      t += y.d;
      cnt++;
    }
    if (!pqt.empty() && t < pqt.top().t) {
      t = pqt.top().t;
    }
  }
  for (int &x : id) {
    cout << x << " ";
  }
  cout << el;
}
