#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

int m = 1e9 + 7;

#define MAXN 1e6
vec<int> spf(MAXN + 5);
void pre() {
  for (int i = 0; i <= MAXN; i++) {
    spf[i] = i;
  }
  for (int i = 2; i <= MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i; j <= MAXN; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}

unordered_map<int, int> fact(int x) {
  unordered_map<int, int> mp;
  while (x > 1) {
    mp[spf[x]]++;
    x /= spf[x];
  }
  return mp;
}

void add(unordered_map<int, int> &mp, unordered_map<int, int> mp1) {
  for (auto i : mp1) {
    mp[i.first] += i.second;
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  unordered_map<int, int> mp;
  for (int i = a; i <= b; i++) {
    add(mp, fact(i));
  }
  int cnt = 1;
  for (auto i : mp) {
    cnt *= (2 * i.second + 1) % m;
    cnt %= m;
  }
  cout << cnt << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pre();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
