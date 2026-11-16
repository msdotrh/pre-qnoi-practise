// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <print>
#include <ranges>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vec<int> red, green, blue;
  for (int i = 0; i < n; i++) {
    char c;
    int l;
    cin >> c >> l;
    if (c == 'r') {
      red.push_back(l);
    } else if (c == 'g') {
      green.push_back(l);
    } else {
      blue.push_back(l);
    }
  }
  ranges::sort(red);
  ranges::sort(green);
  ranges::sort(blue);
  int cnt = 0;
  for (int i = 0; i < red.size(); i++) {
    for (int j = 0; j < green.size(); j++) {
      int x = red[i] + green[j];
      int y = abs(red[i] - green[j]);
      int up = ranges::lower_bound(blue, x) - ranges::begin(blue);
      int low = ranges::upper_bound(blue, y) - ranges::begin(blue);
      if (up > low) {
        cnt += (up - low);
      }
    }
  }
  println("{}", cnt);
}
