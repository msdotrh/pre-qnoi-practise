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
  int n, q;
  cin >> n >> q;
  vec<char> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = i + 'A';
  }

  ranges::stable_sort(a, [](char x, char y) {
    println("? {} {}", x, y);
    fflush(stdout);
    char s;
    cin >> s;
    return s == '<';
  });

  print("! ");
  for (char c : a) {
    print("{}", c);
  }
  fflush(stdout);
}
