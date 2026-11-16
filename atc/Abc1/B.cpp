#include <bits/stdc++.h>
#include <print>
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
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int i = 0, j = 0, k = 0;
  for (int n : a) {
    // how many 1000 yen to pay
    int x = n / 1000 + (n % 1000 != 0);
    int m = x * 1000;
    int r = m - n;
    println(stderr, "{}", r);
    int last = r % 10;
    int second = r % 100 / 10;
    int third = r / 100;
    println(stderr, "xyz => x: {}, y: {}, z: {}", third, second, last);
    k += last;
    j += second;
    i += third;
  }
  println("{} {} {}", k, j, i);
}
