#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  priority_queue<int, vec<int>> pq;
  while (n--) {
    int k;
    cin >> k;
    pq.push(k);
  }
  while (k--) {
    int x = pq.top();
    pq.pop();
    cout << x << " ";
  }
  cout << el;
}
