// #include <@msr.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void open(string inp, string out) {
  string x = inp + ".inp";
  string y = out + ".out";
  freopen(x.c_str(), "r", stdin);
  freopen(y.c_str(), "w", stdout);
}

void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

unordered_map<string, int> d;

void pre() {
  for (int n = 1; n <= 8; n++) {
    string target;
    for (int i = n; i >= 1; i--)
      target.push_back(i + '0');
    queue<string> q;
    q.push(target);
    d[target] = 0;
    while (!q.empty()) {
      string x = q.front();
      q.pop();
      for (int i = 1; i < n; i++) {
        string k = x;
        reverse(k.begin(), k.begin() + i + 1);
        if (d.contains(k))
          continue;
        d[k] = d[x] + 1;
        q.push(k);
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vec<int> a(n);
  for (int &x : a)
    cin >> x;
  vec<int> k = a;
  sort(k.begin(), k.end());
  map<int, int> mp;
  string from;
  for (int i = 0; i < n; i++)
    mp[k[i]] = i + 1;
  for (int i = 0; i < n; i++) {
    int j = mp[a[i]];
    from.push_back(j + '0');
  }
  cout << d[from] << el;
}

signed main() {
  io();
  pre();
  cin >> t;
  while (t--)
    solve();
}
