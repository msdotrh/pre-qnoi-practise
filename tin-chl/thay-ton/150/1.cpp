#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

#define SAFE 10

struct den {
  int s, t;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<den> a(n);
  for (auto &d : a) {
    cin >> d.s >> d.t;
  }
  den mx = *max_element(a.begin(), a.end(),
                        [](den &a, den &b) { return a.t < b.t; });
  vec<int> dd(mx.t + SAFE, 0);
  for (auto &i : a) {
    int l = i.s, r = i.t;
    dd[l]++;
    dd[r + 1]--;
  }

  for (int i = 1; i < dd.size(); i++) {
    dd[i] = dd[i - 1] + dd[i];
  }

  int cnt = 0;
  int mxx = *max_element(dd.begin(), dd.end());
  for (int i : dd) {
    cnt += (mxx == i);
  }
  cout << mxx << el;
  cout << cnt << el;
}
