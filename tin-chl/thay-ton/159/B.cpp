#include <bits/stdc++.h>
#include <concepts>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

multiset<int> ms;

int cal() {
  if (ms.size() == 1) {
    return -1;
  }
  int prev = *ms.begin();
  int mn = INT_MAX;
  for (int x : ms | r::views::drop(1)) {
    int k = abs(x - prev);
    mn = min(mn, k);
    prev = x;
  }
  return mn;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  multiset<int> diff;
  while (q--) {
    char t;
    cin >> t;
    if (t == '+') {
      int x;
      cin >> x;
      ms.insert(x);
      auto it = ms.find(x);
      if (ms.size() == 1) {
        cout << -1 << el;
        continue;
      } else if (ms.size() == 2) {
        diff.insert(abs(*ms.begin() - *ms.rbegin()));
      } else if (it == ms.begin()) {
        diff.insert(abs(x - *next(it)));
      } else if (it == prev(ms.end())) {
        diff.insert(abs(x - *prev(it)));
      } else {
        diff.insert(abs(x - *prev(it)));
        diff.insert(abs(x - *next(it)));
      }
    } else {
      int x;
      cin >> x;
      auto it = ms.find(x);
      int val;
      if (it == ms.begin()) {
        val = abs(x - *next(it));
        auto it = diff.find(val);
        diff.erase(it);
      } else if (it == prev(ms.end())) {
        val = abs(x - *prev(it));
        auto it = diff.find(val);
        diff.erase(it);
      } else {
        val = abs(x - *prev(it));
        int val1 = abs(x - *next(it));
        auto it = diff.find(val);
        auto it1 = diff.find(val1);
        diff.erase(it);
        diff.erase(it1);
      }
      ms.erase(it);
      if (ms.size() == 1) {
        cout << -1 << el;
        continue;
      }
    }
    cout << *ms.begin() << el;
  }
}
