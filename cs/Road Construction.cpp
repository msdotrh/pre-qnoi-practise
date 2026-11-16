// #include <@msr.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

vec<int> lead, len;
int cnt;
int mx;

void make_set() { iota(lead.begin(), lead.end(), 0); }

int find(int v) {
  if (v == lead[v]) {
    return v;
  }
  return lead[v] = find(lead[v]);
}

void unite(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) {
    return;
  }
  if (len[fx] < len[fx]) {
    swap(fx, fy);
  }
  len[fx] += len[fy];
  mx = max(mx, len[fx]);
  lead[fy] = fx;
  cnt--;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  lead.resize(n + 1), len.assign(n + 1, 1);
  cnt = n;
  mx = 1;
  make_set();
  while (m--) {
    int a, b;
    cin >> a >> b;
    unite(a, b);
    cout << cnt << " " << mx << el;
  }
}
