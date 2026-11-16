#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

#define DEN 1
#define AURA 2
#define NONE 0

vec<int> road;
int n, k, r, cnt;

void xuli(int ll, int rr) {
  int size = rr - ll + 1;
  int duongkinh = 2 * r + 1;
  // size nho hon duong kinh
  if (size <= duongkinh) {
    int mid = (ll + rr) / 2;
    cnt++;
    road[mid] = DEN;
    return;
  }
  int mid = ll + r;
  cnt++;
  road[mid] = DEN;
  // ben trai
  if (ll < mid - r) {
    xuli(ll, mid - r - 1);
  }

  // ben phai
  if (mid + r < rr) {
    xuli(mid + r + 1, rr);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k >> r;
  road.assign(n, NONE);
  for (int i = 0; i < k; i++) {
    int j;
    cin >> j;
    j--;
    road[j] = DEN;
    // right
    for (int k = j; k < min(j + r + 1, n); k++) {
      if (road[k] == NONE) {
        road[k] = AURA;
      }
    }
    // left
    for (int k = max(j - r, 0); k < j; k++) {
      if (road[k] == NONE) {
        road[k] = AURA;
      }
    }
  }

  bool f = 0;
  int ll = -1;
  int rr = -1;
  for (int i = 0; i < n; i++) {
    if (road[i] == NONE) {
      f = 1;
      if (ll == -1) {
        // chua set l
        ll = i;
      }
      rr = i;
    } else {
      if (f == 1) {
        f = 0;
        xuli(ll, rr);
        // reset ll, rr
        ll = -1, rr = -1;
      }
    }
  }
  if (f) {
    xuli(ll, rr);
  }
  cout << cnt << el;
}
