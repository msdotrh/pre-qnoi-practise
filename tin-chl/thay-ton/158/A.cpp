#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  priority_queue<int, vec<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    pq.push(k);
  }
  int sum = 0;
  while (pq.size() > 1) {
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    int k = x + y;
    sum += k;
    pq.push(k);
  }
  cout << sum << el;
}
