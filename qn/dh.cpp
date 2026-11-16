// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void open(string inp, string out) {
  string x = inp + ".inp";
  string y = out + ".out";
  freopen(x.c_str(), "r", stdin);
  freopen(y.c_str(), "w", stdout);
}

void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

vec<int> a;

void solve() {
  int n, m;
  cin >> n >> m;
  a.assign(n, 0);
  for (int &x : a) {
    cin >> x;
  }
  int l = 0;
  unordered_multiset<int> st;
  unordered_set<int> st2;
  int mn = MAX;
  for (int r = 0; r < n; r++) {
    st.insert(a[r]);
    st2.insert(a[r]);
    while (st2.size() == m) {
      int sz = st.size();
      mn = min(mn, sz);
      st.erase(st.find(a[l]));
      if (!st.count(a[l])) {
        st2.erase(st2.find(a[l]));
      }
      l++;
    }
  }
  cout << mn << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
