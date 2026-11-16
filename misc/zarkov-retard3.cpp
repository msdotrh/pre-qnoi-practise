#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  int thuong = 0, hoa = 0, so = 0, conlai = 0;
  for (char c : s) {
    if (c >= 'a' && c <= 'z') {
      thuong++;
    } else if (c >= 'A' && c <= 'Z') {
      hoa++;
    } else if (c >= '0' && c <= '9') {
      so++;
    } else {
      conlai++;
    }
  }
  cout << thuong + hoa << '\n';
  cout << so << '\n';
  cout << hoa << '\n';
  cout << thuong << '\n';
  cout << conlai << '\n';
}
