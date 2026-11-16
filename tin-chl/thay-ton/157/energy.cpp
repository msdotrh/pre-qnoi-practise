// #include <@msr.h>
#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int n, s;
vec<int> a;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> s;
  a.resize(n);
  for (int &x : a) {
    cin >> x;
  }
  int sum = s;
  int cnt = 0;
  priority_queue<int, vec<int>, greater<int>> q;
  for (int x : a) {
    if (x < 0) {
      q.push(x);
    }
    sum += x;
    cnt++;
    while (sum < 0 && !q.empty()) {
      sum -= q.top();
      q.pop();
      cnt--;
    }
  }
  cout << cnt << el;
}
