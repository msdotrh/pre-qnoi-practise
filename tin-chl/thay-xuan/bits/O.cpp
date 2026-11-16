// #include <@msr.h>
#include <iostream>
#include <map>
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
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    mp[k]++;
  }
  for (auto x : mp) {
    if (x.second == 1) {
      cout << x.first << " ";
    }
  }
  cout << el;
}
