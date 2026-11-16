#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  bool x = (a + b == 9) || (a - b == 9) || (a * b == 9) ||
           ((a / b == 9) && (a % b == 0));
  println("{}", (x ? "Nine" : "Nein"));
}
