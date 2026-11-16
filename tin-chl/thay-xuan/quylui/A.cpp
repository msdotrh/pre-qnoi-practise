#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
// #define int ll

vec<bool> used;
int cnt = 0;
int n, k;
void action(vec<int> &a) {
  for (int i = 0; i < k; i++) {
    int x = a[i];
    cout << x << " ";
  }
  cout << el;
  cnt++;
}

void tryy(vec<int> &a, int i) {
  for (int j = 1; j <= n; j++) {
    if (used[j]) {
      continue;
    }

    a[i] = j;
    used[j] = 1;

    if (i == k - 1) {
      action(a);
    } else {
      tryy(a, i + 1);
    }
    // bo j
    used[j] = 0;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> k >> n;
  vec<int> a(n, 0);
  used.assign(n + 1, 0);
  tryy(a, 0);
  cout << cnt << el;
}
