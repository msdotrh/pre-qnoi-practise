// #include <@msr.h>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

const int MAXN = 1e6 + 1;
vec<int> sp(MAXN + 5, 1);
void pre() {
  for (int i = 2; i <= MAXN; i++) {
    for (int j = i; j <= MAXN; j += i) {
      sp[j] += i;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  pre();
  while (n--) {
    int k;
    cin >> k;
    cout << sp[k] << " ";
  }
  cout << el;
}
