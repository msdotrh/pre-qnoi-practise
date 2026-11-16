#include <bits/stdc++.h>
#include <unordered_map>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

const int MAXN = 1e6 + 5;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vec<int> f1(MAXN, 0);
  vec<int> f2(MAXN, 0);
  unordered_set<int> st1;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    f1[k]++;
    st1.insert(k);
  }
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    f2[k]++;
    st1.insert(k);
  }
  int cnt = 0;
  for (int i : st1) {
    cnt += f1[i] * f2[i];
  }
  cout << cnt << el;
}
