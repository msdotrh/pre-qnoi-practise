// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
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

vec<int> len;
vec<int> lead;
int n, m;

void init() {
  lead.assign(n + 1, 0);
  iota(lead.begin(), lead.end(), 0);
  len.assign(n + 1, 1);
}

int look(int x) {
  if (lead[x] == x) {
    return x;
  }
  return lead[x] = look(lead[x]);
}

void unite(int a, int b) {
  int la = look(a);
  int lb = look(b);
  if (len[la] < len[lb]) {
    swap(len[la], len[lb]);
  }
  // hop lai
  lead[lb] = la;
  len[la] += len[lb];
}

void solve() {
  cin >> n >> m;
  init();
  while (m--) {
    int a, b;
    cin >> a >> b;
    unite(a, b);
  }
  vec<int> mxlen;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    if (st.contains(lead[i]))
      continue;
    mxlen.push_back(len[lead[i]]);
    st.insert(lead[i]);
  }
  r::sort(mxlen, greater<int>());
  cout << mxlen[0] + mxlen[1] << el;
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
