#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

int f(int n) {
  int curr = 1, prev = 0;
  for (int i = 0; i < n; i++) {
    int temp = curr;
    curr = curr + prev;
    prev = temp;
  }
  return prev;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  cout << f(n);
}
