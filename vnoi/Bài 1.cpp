// #include <@msr.h>
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
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
  string s;
  getline(cin, s);
  for (char c : s | ranges::views::filter([](char c) { return isalpha(c); })) {
    cout << c;
  }
  cout << el;
}
