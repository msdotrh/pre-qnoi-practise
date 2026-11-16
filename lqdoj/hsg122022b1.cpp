// #include <@msr.h>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("DEMCAP.INP", "r", stdin);
  freopen("DEMCAP.OUT", "w", stdout);
  int n;
  cin >> n;
  if (n % 2) {
    cout << n / 2;
  } else {
    cout << n / 2 - 1;
  }
  cout << el;
}
