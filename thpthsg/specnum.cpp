// #include <@msr.h>
#include <iostream>
#include <map>
#include <print>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

const int MAXN = 1e4;

int ds(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int l, r;
  cin >> l >> r;
  map<int, int> mp;
  for (int i = l; i <= r; i++) {
    int dig = ds(i);
    println("{}: {}", i, dig);
    mp[dig]++;
  }
  for (auto x : mp) {
    println("{}: cnt[{}]", x.first, x.second);
  }
}
