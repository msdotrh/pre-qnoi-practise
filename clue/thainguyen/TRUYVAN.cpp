#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

multiset<int> ms;

void add() {
  int k;
  cin >> k;
  ms.insert(k);
}

void del() {
  int k;
  cin >> k;
  auto it = ms.find(k);
  if (it != ms.end()) {
    ms.erase(it);
  }
}

void query() {
  int k;
  cin >> k;
  auto i = ms.begin();
  i = next(i, k - 1);
  cout << *i << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    ms.insert(x);
  }
  int q;
  cin >> q;
  while (q--) {
    char x;
    cin >> x;
    if (x == 'A') {
      add();
    } else if (x == 'D') {
      del();
    } else {
      query();
    }
  }
}
