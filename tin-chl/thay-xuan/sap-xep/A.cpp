#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  unordered_set<int> us;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    us.insert(k);
  }
  cout << us.size() << el;
}
