#include <bits/stdc++.h>
// #include <@msr.h>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

void mod(string s) {
  stringstream ss(s);

  string x;
  while (ss >> x) {
    cout << static_cast<char>(toupper(x.front()));
    x = x | views::drop(1) | std::views::transform([](char c) {
          return static_cast<char>(tolower(c));
        }) |
        ranges::to<string>();
    cout << x << " ";
  }
  cout << el;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    string s;
    getline(cin, s);
    cout << s << el;
    mod(s);
  }
}
